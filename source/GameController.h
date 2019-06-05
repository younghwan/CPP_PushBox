#pragma once
#include "PushBoxGame.h"
#include "GameViewer.h"

class GameController {
public:
	GameController() {};
	void gameInitialize();
	void gameDelete();
	void postProcessing();
	bool IsinMapNow();
	bool IsinMapNow(int dy, int dx);
	bool CheckPosition(Coordinates userposition);
	void move(Coordinates userposition);
	bool isSuccess();
	WINDOW* levelBoard, * stepBoard, * pushBoard, * timeBoard, * gameBoard;
	PushBoxGame pushBoxGame;
	void test() {
		pushBoxGame.map[0][0] = 2;

	}

private:
	int b = pushBoxGame.getLevel();
	const int FINALLEVEL = 5;
	GameViewer gameViewer;
};