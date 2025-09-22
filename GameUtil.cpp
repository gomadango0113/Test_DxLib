#include <DxLib.h>

void drawTextCenter(int x, int y, const char* string, int size, int text_color, int edge_color) {
    SetFontSize(size);
    int strWidth = GetDrawStringWidth(string, strlen(string));
    x -= strWidth / 2;
    y -= size / 2;
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
    DrawString(x, y, string, text_color, edge_color);
}

//âÊëúÇíÜêSÇ…ï`Ç≠
void drawImageCenter(int img, int x, int y, float size) {
    int w, h;
    GetGraphSize(img, &w, &h);

    int change_size_w = w * size;
    int change_size_h = h * size;
    int leftX = x - change_size_w / 2;
    int leftY = y - change_size_h / 2;
    int rightX = x + change_size_w / 2;
    int rightY = y + change_size_h / 2;
    DrawExtendGraph(leftX, leftY, rightX, rightY, img, TRUE);
}