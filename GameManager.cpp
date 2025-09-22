#include <DxLib.h>
#include "GameManager.h"
#include "main.h"

int player_image;
GameStatus status;
ObjectDxLibImage player_object;

//ƒQ[ƒ€‚ð‰Šú‰»‚·‚éŠÖ”
int initGame() {
	status = GameStatus::TITLE;
	player_image = LoadGraph("image/stand1_front10_obaasan_long.png");
	player_object = { WIDTH * 0.2, HEIGHT * 0.65, 3.0, 3.0, player_image };

	return 0;
}

void jump() {
    player_object.y -= player_object.vectorY;
    player_object.vectorY -= 1;

    if (player_object.y > HEIGHT * 0.8) {
        player_object.y = HEIGHT * 0.8;
        player_object.vectorY = 0;
    }
}