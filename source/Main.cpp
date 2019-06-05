#include "GameController.h"

int main()
{
	
	
	PushBoxGame pushBoxGame;
	GameViewer gameViewer;
	GameController gameController;

	gameController.gameInitialize();
	gameViewer.renderAll(gameController.levelBoard, gameController.stepBoard, gameController.pushBoard, gameController.timeBoard, gameController.gameBoard);
	gameController.test();
	int asdf = 0;
	while (true) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if(gameController.pushBoxGame.map[i][j]==5)
				{
					gameController.pushBoxGame.setUserPosition(Coordinates(j,i));
				}
			}
		}
		int ch = getch();
		keypad(stdscr, TRUE);
		mvwprintw(gameController.stepBoard, 1, 8, "%d", asdf);
		asdf += 1;
		switch (ch)
		{
		case KEY_UP: //up
			gameController.move(Coordinates(0, -1));
			break;
		case KEY_DOWN: //down
			gameController.move(Coordinates(0, 1));
			break;
		case KEY_RIGHT: //right
			gameController.move(Coordinates(1, 0));
			break;
		case KEY_LEFT: //left
			gameController.move(Coordinates(-1, 0));
			break;
		}
		gameViewer.renderAll(gameController.levelBoard, gameController.stepBoard, gameController.pushBoard, gameController.timeBoard, gameController.gameBoard);

	}




	getch();
	gameController.gameDelete();


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	WINDOW* levelBoard, * stepBoard, * pushBoard, * timeBoard, * gameBoard;

	setlocale(LC_CTYPE, "ko_KR.utf-8");
	initscr();
	resize_term(35, 95);
	start_color();
	curs_set(0);
	noecho();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	border('*', '-', '*', '*', '*', '*', '*', '*');
	refresh();

	gameBoard = newwin(27, 70, 4, 2);
	levelBoard = newwin(3, 15, 8, 75);
	stepBoard = newwin(3, 15, 12, 75);
	pushBoard = newwin(3, 15, 16, 75);
	timeBoard = newwin(3, 15, 20, 75);
	wbkgd(levelBoard, COLOR_PAIR(1));
	wattron(levelBoard, COLOR_PAIR(1));
	wbkgd(stepBoard, COLOR_PAIR(1));
	wattron(stepBoard, COLOR_PAIR(1));
	wbkgd(pushBoard, COLOR_PAIR(1));
	wattron(pushBoard, COLOR_PAIR(1));
	wbkgd(timeBoard, COLOR_PAIR(1));
	wattron(timeBoard, COLOR_PAIR(1));

	mvwprintw(levelBoard, 1, 1, "level: ");
	mvwprintw(levelBoard, 1, 8, " ");
	mvwprintw(stepBoard, 1, 1, "move: ");
	mvwprintw(stepBoard, 1, 8, " ");
	mvwprintw(pushBoard, 1, 1, "goal: ");
	mvwprintw(pushBoard, 1, 8, " ");
	mvwprintw(timeBoard, 1, 1, "time: ");
	mvwprintw(timeBoard, 1, 8, " ");
	wborder(levelBoard, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(stepBoard, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(pushBoard, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(timeBoard, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(gameBoard, '|', '|', '-', '-', '+', '+', '+', '+');

	wrefresh(levelBoard);
	wrefresh(stepBoard);
	wrefresh(pushBoard);
	wrefresh(timeBoard);
	wrefresh(gameBoard);

	//PushBoxGame game;
	//while (true)
	//	{	
	//	for (int i = 0; i < 10; i++) {
	//		for (int j = 0; j < 10; j++) {
	//			if(game.map[i][j]==5)
	//			{
	//				game.setX(j);
	//				game.setY(i);
	//				
	//			}
	//		}
	//	}
	//	int ch = getch();
 //   	keypad(stdscr,TRUE);	
	//	
 //         Position movePos;
 //         switch(ch)
 //         {
 //             case KEY_UP: //up
 //             movePos.x =0;
 //             movePos.y =-1;
	//		  game.move(movePos);
	//		  break;
 //             case KEY_DOWN: //down
 //             movePos.x =0;
 //             movePos.y =1;
	//		  game.move(movePos);
	//		  break;
 //             case KEY_RIGHT: //right
 //             movePos.x =1;
 //             movePos.y =0;
	//		  game.move(movePos);
	//		  break;
 //             case KEY_LEFT: //left
 //             movePos.x =-1;
 //             movePos.y =0;
	//		  game.move(movePos);
	//		  break;
 //         }

	//	  for (int i = 0; i < 10; i++) {
	//		for (int j = 0; j < 10; j++) {
	//			switch (game.map[i][j])
	//			{
	//			case EMPTY:mvwprintw(gameBoard, i + 1, j + 1, " ");
	//				break;
	//			case WALL:mvwprintw(gameBoard, i + 1, j + 1, "#");
	//				break;
	//			case BOX:mvwprintw(gameBoard, i + 1, j + 1, "□");
	//				break;
	//			case HOLE:mvwprintw(gameBoard, i + 1, j + 1, "c");
	//				break;
	//			case BOUND:mvwprintw(gameBoard, i + 1, j + 1, " ");
	//				break;
	//			case PLAYER:mvwprintw(gameBoard, i + 1, j + 1, "*");
	//				break;	
	//			}
	//		}
	//	} 
	// 
	//wrefresh(levelBoard);
	//wrefresh(stepBoard);
	//wrefresh(pushBoard);
	//wrefresh(timeBoard);
	//wrefresh(gameBoard);
	//	}
	getch();

	delwin(levelBoard);
	delwin(stepBoard);
	delwin(pushBoard);
	delwin(timeBoard);
	delwin(gameBoard);
	endwin();
	*/

	return 0;
}
