#pragma once

int initGame(); //�Q�[��������������֐�
void jump();

enum GameStatus {
	TITLE, //�^�C�g�����
	RUNNING, //���s��
	ENDING //�I�����
};

struct ObjectDxLibImage {
	float x;
	float y;
	float vectorX;
	float vectorY;
	int image_handle;
	bool TransFlag;
};

extern int player_image;

extern GameStatus status;

extern ObjectDxLibImage player_object;