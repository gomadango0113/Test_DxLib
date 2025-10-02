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
    int w = 20;
    int h = 40;

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
            DrawBox(player_object.x - w / 2, player_object.y - h / 2, player_object.x + w /2, player_object.y + h / 2, GetColor(255,255,255), true);

            for (int y = 0; y < MAP_HEIGHT; y++) {
                for (int x = 0; x < MAP_WIDTH; x++) {
                    int map_x = x * MAP_PIXEL;
                    int map_y = y * MAP_PIXEL;

                    int player_mapX = player_object.x / MAP_PIXEL;
                    int player_mapY = player_object.y / MAP_PIXEL;

                    if (MAP[y][x] == 1) {
                        DrawBox(map_x, map_y, map_x + MAP_PIXEL, map_y + MAP_PIXEL, GetColor(255, 255, 255), true);
                    }
                }
            }


            if (CheckHitKey(KEY_INPUT_LEFT)) {
                player_object.x -= player_object.vectorX;
            }
            if (CheckHitKey(KEY_INPUT_RIGHT)) {
                player_object.x += player_object.vectorX;
            }
            if (CheckHitKey(KEY_INPUT_SPACE) && player_object.y >= downY) {
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