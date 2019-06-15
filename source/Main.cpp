#include "GameController.h"

int main()
{
	PushBoxGame pushBoxGame;
	GameViewer gameViewer(&pushBoxGame);
	GameController gameController(&pushBoxGame, &gameViewer);

	gameController.gameInitialize();
	gameViewer.renderAll(gameController.levelBoard, gameController.stepBoard, gameController.pushBoard, gameController.resetBoard, gameController.gameBoard);
	keypad(stdscr, TRUE);

	while (true) {
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
		case KEY_HOME:
			gameController.goNextLevel();
			break;
		case 'r':
		case 'R':
			gameController.reset();
			break;
		case 'q':
		case 'Q':
			goto end;
			break;
		}
		bool t = gameController.postProcessing();
		if (t) goto end;
	}
end:
	gameController.gameDelete();

	return 0;
}
