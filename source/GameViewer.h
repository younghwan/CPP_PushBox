#pragma once
#include "PushBoxGame.h"
#include "GameController.h"

class GameViewer {
public:
	GameViewer() {};
	void test() {
		pushBoxGame.map[0][0] = 2;

	}

	void setPushBoxGame(PushBoxGame& pushBoxGame) {
		this->pushBoxGame = pushBoxGame;
	}

	void renderLevelBoard(WINDOW* levelBoard) {
		mvwprintw(levelBoard, 1, 8, " ");
		wrefresh(levelBoard);
		return;
	}

	void renderStepBoard(WINDOW* stepBoard) {
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
	void renderGameBoard(WINDOW *gameBoard) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j += 2) {
				switch (pushBoxGame.map[i][j / 2])
				{
				case EMPTY:mvwprintw(gameBoard, i + 1, j + 1, " ");
					break;
				case WALL:mvwprintw(gameBoard, i + 1, j + 1, "бс");
					break;
				case BOX:mvwprintw(gameBoard, i + 1, j + 1, "бр");
					break;
				case HOLE:mvwprintw(gameBoard, i + 1, j + 1, "в═");
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