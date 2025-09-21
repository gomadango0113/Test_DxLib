#include <DxLib.h>
#include <stdlib.h>
#include <list>
#include "GameUtil.h"
#define FPS 60

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
    std::list<ObjectDxLib3D> object_3d_list = {};

    SetWindowText("ああああああああああああああああ");
    SetGraphMode(1280, 720, 32);
    ChangeWindowMode(true);
    if (DxLib_Init() == -1) {
        return -1;
    }
    SetBackgroundColor(0, 255, 0);
    SetDrawScreen(DX_SCREEN_BACK);

    ObjectDxLib3D object_3d = { 320.0f, 200.0f, 0.0f, 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE };
    object_3d_list.push_back(object_3d);

    int mouseX, mouseY; //マウスの座標
    float speed = 3.0;

    while (true) {
        ClearDrawScreen();
        GetMousePoint(&mouseX, &mouseY);

        SetUseZBuffer3D(TRUE);
        SetWriteZBuffer3D(TRUE);

        for (auto it = object_3d_list.begin(); it != object_3d_list.end(); ++it) {
            ObjectDxLib3D& object = *it;
            if (CheckHitKey(KEY_INPUT_W)) {
                object.z+=speed;
            }
            if (CheckHitKey(KEY_INPUT_S)) {
                object.z -= speed;
            }
            if (CheckHitKey(KEY_INPUT_A)) {
                object.x -= speed;
            }
            if (CheckHitKey(KEY_INPUT_D)) {
                object.x += speed;
            }
            if (CheckHitKey(KEY_INPUT_SPACE)) {
                object.y += speed;
            }
            if (CheckHitKey(KEY_INPUT_LSHIFT)) {
                object.y -= speed;
            }
            
            DrawSphere3D(VGet(object.x, object.y, object.z), object.radius, object.DivNum, object.object_color, object.specular_color, object.FillFlag);
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