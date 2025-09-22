#pragma once

void drawTextCenter(int x, int y, const char* string, int size, int text_color, int edge_color);
void drawImageCenter(int img, int x, int y, float size);

struct ObjectDxLib3D {
	float x; //ベクトルx
	float y; //ベクトルy
	float z; //ベクトルz
	float radius; //半径
	int DivNum;  //オブジェクトの細かさ
	unsigned int object_color; //オブジェクトの色
	unsigned int specular_color; //オブジェクトの反射色
	bool FillFlag; //塗りつぶすか
};