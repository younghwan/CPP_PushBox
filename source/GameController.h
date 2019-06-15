#pragma once
#include "PushBoxGame.h"
#include "GameViewer.h"

class GameController {
public:
	GameController() {};
	GameController(PushBoxGame* model, GameViewer* view)
	{
		pushBoxGame = model;
		gameViewer = view;
	}
	void setGoalPos(vector<Coordinates> goalposition);
	void gameInitialize();
	void gameDelete();
	bool IsinMapNow();
	bool IsinMapNow(int dy, int dx);
	bool CheckPosition(Coordinates userPos);
	void move(Coordinates userPos);
	void postProcessing();
	bool isSuccess();
	WINDOW* levelBoard, * stepBoard, * pushBoard, * resetBoard, * gameBoard;
	void goNextLevel();
	void reset();
	void startGame();
private:
	const int FINALLEVEL = 5;
	PushBoxGame *pushBoxGame;
	GameViewer *gameViewer;
};