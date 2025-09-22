#pragma once

void drawTextCenter(int x, int y, const char* string, int size, int text_color, int edge_color);
void drawImageCenter(int img, int x, int y, float size);

struct ObjectDxLib3D {
	float x; //�x�N�g��x
	float y; //�x�N�g��y
	float z; //�x�N�g��z
	float radius; //���a
	int DivNum;  //�I�u�W�F�N�g�ׂ̍���
	unsigned int object_color; //�I�u�W�F�N�g�̐F
	unsigned int specular_color; //�I�u�W�F�N�g�̔��ːF
	bool FillFlag; //�h��Ԃ���
};