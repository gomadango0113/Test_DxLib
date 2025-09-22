#pragma once

int initGame(); //ゲームを初期化する関数
void jump();

enum GameStatus {
	TITLE, //タイトル画面
	RUNNING, //実行中
	ENDING //終了画面
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