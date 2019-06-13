#include "GameController.h"

int main()
{
	PushBoxGame pushBoxGame;
	GameViewer gameViewer(pushBoxGame);
	GameController gameController(pushBoxGame, gameViewer);

	gameController.gameInitialize();
	gameViewer.renderAll(gameController.levelBoard, gameController.stepBoard, gameController.pushBoard, gameController.timeBoard, gameController.gameBoard);
	while (true) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (pushBoxGame.getMap(i, j) == 5)
				{
					gameController.pushBoxGame.setUserPos(Coordinates(j, i));
				}
			}
		}
		keypad(stdscr, TRUE);
		switch (getch())
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
		case 'n':
			gameController.goNextLevel();
			break;
		}
		
		gameController.setGoalPos(pushBoxGame.getGoalList());
		gameController.postProcessing();
		//gameViewer.renderAll(gameController.levelBoard, gameController.stepBoard, gameController.pushBoard, gameController.timeBoard, gameController.gameBoard);
		
	}

	getch();
	gameController.gameDelete();

	return 0;
}
