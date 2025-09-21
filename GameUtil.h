#pragma once

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