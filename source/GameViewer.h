#pragma once
#include "PushBoxGame.h"
#include "GameController.h"


class GameViewer {
public:
	GameViewer() {};
	GameViewer(PushBoxGame* model)
	{
		pushBoxGame = model;
	}
	void startview(WINDOW* startMenu) {

		startMenu = newwin(19, 40, 6, 2);
	}
	void renderLevelBoard(WINDOW* levelBoard) {
		mvwprintw(levelBoard, 1, 8, "%d", pushBoxGame->getLevel());
		wrefresh(levelBoard);
		return;
	}
	void renderStepBoard(WINDOW* stepBoard) {
		mvwprintw(stepBoard, 1, 8, "%d", pushBoxGame->getStep());
		wrefresh(stepBoard);
		return;
	}
	void renderPushBoard(WINDOW* pushBoard) {
		mvwprintw(pushBoard, 1, 8, "%d", pushBoxGame->getPush());
		wrefresh(pushBoard);
		return;
	}
	void renderTimeBoard(WINDOW* resetBoard) {
		mvwprintw(resetBoard, 1, 8, "%d", pushBoxGame->getReset());
		wrefresh(resetBoard);
		return;
	}
	void renderGameBoard(WINDOW* gameBoard) {
		int rowHandle = (15 - pushBoxGame->getRow()) / 2;
		int colHandle = (38 - pushBoxGame->getCol() * 2) / 2 + 1;
		int ux = pushBoxGame->getX_userPos();
		int uy = pushBoxGame->getY_userPos();
		char temp = pushBoxGame->getMap(uy, ux);
		pushBoxGame->setMap(Coordinates(uy, ux), PLAYER);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				switch (pushBoxGame->getMap(i, j / 2))
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
		pushBoxGame->setMap(Coordinates(uy, ux), temp);
		return;
	};
	void renderAll(WINDOW* levelBoard, WINDOW* stepBoard, WINDOW* pushBoard, WINDOW* resetBoard, WINDOW* gameBoard) {
		renderLevelBoard(levelBoard);
		renderStepBoard(stepBoard);
		renderPushBoard(pushBoard);
		renderTimeBoard(resetBoard);
		renderGameBoard(gameBoard);
	}
	void renderInit(WINDOW* levelBoard, WINDOW* stepBoard, WINDOW* pushBoard, WINDOW* resetBoard) {
		mvwprintw(levelBoard, 1, 8, "   ");
		mvwprintw(stepBoard, 1, 8, "   ");
		mvwprintw(pushBoard, 1, 8, "   ");
		mvwprintw(resetBoard, 1, 8, "   ");
	}
private:
	PushBoxGame *pushBoxGame;
};