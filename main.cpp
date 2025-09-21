#include <DxLib.h>
#define FPS 60

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
    SetWindowText("‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ‚ ");
    SetGraphMode(1280, 720, 32);
    ChangeWindowMode(true);
    if (DxLib_Init() == -1) {
        return -1;
    }
    SetBackgroundColor(0, 0, 0);
    SetDrawScreen(DX_SCREEN_BACK);

    while (true) {
        ClearDrawScreen();

        ScreenFlip();
        WaitTimer(1000 / FPS);
        if (ProcessMessage() == -1) {
            break;
        }
    }

    DxLib_End();
    return 0;
}