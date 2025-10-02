#include <DxLib.h>
#include "GameManager.h"
#include "main.h"

int player_image;
GameStatus status;
ObjectDxLibImage player_object;
int downY = HEIGHT * 0.9;

//ゲームを初期化する関数
int initGame() {
	status = GameStatus::TITLE;
	player_image = LoadGraph("image/stand1_front10_obaasan_long.png");
	player_object = { WIDTH * 0.2, HEIGHT * 0.9, 3.0, 3.0, player_image };

	return 0;
}

void jump() {
    int player_nextY = player_object.y - player_object.vectorY;

    int player_mapX = player_object.x / MAP_PIXEL; //中心X
    int player_mapY = player_object.y / MAP_PIXEL; //中心Y

    //ワールド座標系
    int leftUpX = player_object.x - MAP_PIXEL, leftUpY = player_object.y - MAP_PIXEL;
    int leftDownX = player_object.x - MAP_PIXEL, leftDownY = player_object.y + MAP_PIXEL;
    int rightUpX = player_object.x + MAP_PIXEL, rightUpY = player_object.y + MAP_PIXEL;
    int rightDownX = player_object.x + MAP_PIXEL, rightDownY = player_object.y - MAP_PIXEL;

    int down_arrayY = (player_nextY + MAP_PIXEL) / MAP_PIXEL;

    int leftUp_value = MAP[leftUpY / MAP_PIXEL][leftUpX / MAP_PIXEL];
    int rightUp_value = MAP[rightUpY / MAP_PIXEL][rightUpX / MAP_PIXEL];
    int leftDown_value = MAP[down_arrayY][leftDownX / MAP_PIXEL];
    int rightDown_value = MAP[down_arrayY][rightDownX / MAP_PIXEL];

    DrawFormatString(0, 0, GetColor(255, 255, 255), "%d %d %d %d %d", leftUp_value, rightUp_value, leftDown_value, rightDown_value, downY);

    if (leftDown_value == 1 || rightDown_value == 1) {
        player_object.y = down_arrayY * MAP_PIXEL - MAP_PIXEL;
        player_object.vectorY = 0;
    }
    else {
        player_object.y -= player_object.vectorY;
        player_object.vectorY -= 1;
    }

    /*
    int leftUpX = 0, leftUpY = 0;
    int leftDownX = 0, leftDownY = 0;
    int rightUpX = 0, rightUpY = 0;
    int rightDownX = 0, rightDownY = 0;
    */
}