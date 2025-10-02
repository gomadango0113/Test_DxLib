#include "DxLib.h"
#include <stdlib.h>
#include <list>
#include "GameUtil.h"
#include "GameManager.h"
#include "main.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
    std::list<ObjectDxLib3D> object_3d_list = {};

    SetWindowText("ああああああああああああああああ");
    SetGraphMode(WIDTH, HEIGHT, COLOR_BIT);
    ChangeWindowMode(true);
    if (DxLib_Init() == -1 || initGame() == -1) {
        MessageBox(NULL, "ゲームを初期化することができませんでした。", NULL, MB_OK | MB_ICONERROR);
        DxLib_End();
        return -1;
    }
    SetBackgroundColor(0, 255, 0);
    SetDrawScreen(DX_SCREEN_BACK);

    int mouseX, mouseY; //マウスの座標

    while (true) {
        ClearDrawScreen();
        GetMousePoint(&mouseX, &mouseY);

        switch (status)
        {
        case TITLE:
            drawTextCenter(WIDTH * 0.5, HEIGHT * 0.5, "ゲームを開始するにはスペースキー", 30, GetColor(0, 0, 0), GetColor(255, 255, 255));
            if (CheckHitKey(KEY_INPUT_SPACE)) {
                status = RUNNING;
            }
            break;
        case RUNNING:
            drawImageCenter(player_object.image_handle, player_object.x, player_object.y, 0.2);

            if (CheckHitKey(KEY_INPUT_LEFT)) {
                player_object.x -= player_object.vectorX;
            }
            if (CheckHitKey(KEY_INPUT_RIGHT)) {
                player_object.x += player_object.vectorX;
            }
            if (CheckHitKey(KEY_INPUT_SPACE) && player_object.y >= HEIGHT * 0.8) {
                player_object.vectorY = 10;
            }

            jump();
            break;
        case ENDING:
            break;
        default:
            break;
        }

        ScreenFlip();
        WaitTimer(1000 / FPS);
        if (ProcessMessage() == -1) {
            break;
        }
    }

    DxLib_End();
    return 0;
}