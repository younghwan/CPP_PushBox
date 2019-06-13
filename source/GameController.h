#pragma once
#include "PushBoxGame.h"
#include "GameViewer.h"

class GameController {
public:
	GameController() {};
	GameController(const PushBoxGame& model, const GameViewer& view)
	{
		this->pushBoxGame = model;
		this->gameViewer = view;
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
	WINDOW* levelBoard, * stepBoard, * pushBoard, * timeBoard, * gameBoard;
	PushBoxGame pushBoxGame;
	void goNextLevel();

private:
	const int FINALLEVEL = 5;
	GameViewer gameViewer;
};