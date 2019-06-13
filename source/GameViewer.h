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
		mvwprintw(levelBoard, 1, 8, "%d", pushBoxGame.getGoalList()[1].x);
		wrefresh(levelBoard);
		return;
	}
	void renderStepBoard(WINDOW* stepBoard) {
		int i = pushBoxGame.getStep();
		
		mvwprintw(stepBoard, 1, 8, "%d", pushBoxGame.getMap(pushBoxGame.getGoalList()[i].x, pushBoxGame.getGoalList()[i].y) );
		wrefresh(stepBoard);
		return;
	}
	void renderPushBoard(WINDOW* pushBoard) {
		mvwprintw(pushBoard, 1, 8, "%d", pushBoxGame.getGoalList()[1].x);
		wrefresh(pushBoard);
		return;
	}
	void renderTimeBoard(WINDOW* timeBoard) {
		mvwprintw(timeBoard, 1, 8, " ");
		wrefresh(timeBoard);
		return;
	}
	void renderGameBoard(WINDOW* gameBoard) {
		int rowHandle = (19 - pushBoxGame.getRow()) / 2;
		int colHandle = (40 - pushBoxGame.getCol() * 2) / 2;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				switch (pushBoxGame.getMap(i, j / 2))
				{
				case EMPTY:
					wattron(gameBoard, COLOR_PAIR(2));
					mvwprintw(gameBoard, i + rowHandle, j + colHandle, " ");
					wattroff(gameBoard, COLOR_PAIR(2));
					break;
				case WALL:
					wattron(gameBoard, COLOR_PAIR(3));
					mvwprintw(gameBoard, i + rowHandle, j + colHandle, " ");
					wattroff(gameBoard, COLOR_PAIR(3));
					break;
				case BOX:
					wattron(gameBoard, COLOR_PAIR(4));
					if (j % 2 == 0) {
						mvwprintw(gameBoard, i + rowHandle, j + colHandle, "I");
					}
					else {
						mvwprintw(gameBoard, i + rowHandle, j + colHandle, "I");
					}
					wattroff(gameBoard, COLOR_PAIR(4));
					break;
				case GOAL:
					wattron(gameBoard, COLOR_PAIR(5));
					if (j % 2 == 0) {
						mvwprintw(gameBoard, i + rowHandle, j + colHandle, ">");
					}
					else
					{
						mvwprintw(gameBoard, i + rowHandle, j + colHandle, "<");
					}
					wattroff(gameBoard, COLOR_PAIR(5));
					break;
				case BOUND:mvwprintw(gameBoard, i + rowHandle, j + colHandle, " ");
					break;
				case PLAYER:
					wattron(gameBoard, COLOR_PAIR(6));
					if (j % 2 == 0) {
						mvwprintw(gameBoard, i + rowHandle, j + colHandle, "'");
					}
					else
					{
						mvwprintw(gameBoard, i + rowHandle, j + colHandle, "'");
					}
					wattroff(gameBoard, COLOR_PAIR(6));
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