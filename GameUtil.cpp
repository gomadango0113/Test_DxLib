#include <DxLib.h>

void drawTextCenter(int x, int y, const char* string, int size, int text_color, int edge_color) {
    SetFontSize(size);
    int strWidth = GetDrawStringWidth(string, strlen(string));
    x -= strWidth / 2;
    y -= size / 2;
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
    DrawString(x, y, string, text_color, edge_color);
}