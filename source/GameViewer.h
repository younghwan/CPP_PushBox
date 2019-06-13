#pragma once
#include "PushBoxGame.h"
#include "GameController.h"


class GameViewer {
public:
	GameViewer() {};
	GameViewer(const PushBoxGame& model)
	{
		this->pushBoxGame = model;
	}

	void renderLevelBoard(WINDOW* levelBoard) {
		mvwprintw(levelBoard, 1, 8, " ");
		wrefresh(levelBoard);
		return;
	}
	void renderStepBoard(WINDOW* stepBoard) {
		int i = pushBoxGame.getStep();
		mvwprintw(stepBoard, 1, 8, " ");
		wrefresh(stepBoard);
		return;
	}
	void renderPushBoard(WINDOW* pushBoard) {
		mvwprintw(pushBoard, 1, 8, " ");
		wrefresh(pushBoard);
		return;
	}
	void renderTimeBoard(WINDOW* timeBoard) {
		mvwprintw(timeBoard, 1, 8, " ");
		wrefresh(timeBoard);
		return;
	}
	void renderGameBoard(WINDOW* gameBoard) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				switch (pushBoxGame.getMap(i, j))
				{
				case EMPTY:mvwprintw(gameBoard, i + 1, j + 1, " ");
					break;
				case WALL:mvwprintw(gameBoard, i + 1, j + 1, "#");
					break;
				case BOX:mvwprintw(gameBoard, i + 1, j + 1, "B");
					break;
				case GOAL:mvwprintw(gameBoard, i + 1, j + 1, "X");
					break;
				case BOUND:mvwprintw(gameBoard, i + 1, j + 1, " ");
					break;
				case PLAYER:mvwprintw(gameBoard, i + 1, j + 1, "P");
					break;
				}
			}
		}
		wrefresh(gameBoard);
		return;
	};
	void renderAll(WINDOW* levelBoard, WINDOW* stepBoard, WINDOW* pushBoard, WINDOW* timeBoard, WINDOW* gameBoard) {
		renderLevelBoard(levelBoard);
		renderStepBoard(stepBoard);
		renderPushBoard(pushBoard);
		renderTimeBoard(timeBoard);
		renderGameBoard(gameBoard);
	}

private:
	PushBoxGame pushBoxGame;
};