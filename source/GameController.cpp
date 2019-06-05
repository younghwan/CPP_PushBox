#include "GameController.h"

//GameController::GameController(  GameViewer& gameViewer)
//{
//	//this->pushBoxGame = pushBoxGame;
//	this->gameViewer = gameViewer;
//}



void GameController::gameInitialize() {
	setlocale(LC_CTYPE, "ko_KR.utf-8");
	initscr();
	resize_term(35, 95);
	start_color();
	curs_set(0);
	noecho();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	border('*', '*', '*', '*', '*', '*', '*', '*');
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

	//wrefresh(levelBoard);
	//wrefresh(stepBoard);
	//wrefresh(pushBoard);
	//wrefresh(timeBoard);
	//wrefresh(gameBoard);
}

void GameController::gameDelete() {
	delwin(levelBoard);
	delwin(stepBoard);
	delwin(pushBoard);
	delwin(timeBoard);
	delwin(gameBoard);
	endwin();
	return;
}

void GameController::postProcessing()
{
	//showWithPlayer();
	if (isSuccess()) {
		vector<int> rec;
		rec.push_back(pushBoxGame.getStep());
		rec.push_back(pushBoxGame.getPush());
		//rec.push_back((int)(startTimer - endTimer));
		pushBoxGame.addRecords(rec);
		if (pushBoxGame.getLevel() == FINALLEVEL) {
			cout << "##### Congraturation! You complete final level #####" << endl;
		}
		else {
			cout << "############## SUCCESS ##############" << endl;
			pushBoxGame.setLevel(pushBoxGame.getLevel() + 1);
			pushBoxGame.setStep(0);
			pushBoxGame.setPush(0);
			pushBoxGame.readMap();
		}
	}
	return;
}


bool GameController::isSuccess()
{
	for (int i = 0; i < pushBoxGame.getGoalList().size(); i++) {
		int x = pushBoxGame.getGoalList()[i].x;
		int y = pushBoxGame.getGoalList()[i].y;
		if (pushBoxGame.map[x][y] == 2) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}
//void PushBoxGame::testGoToLevel2()
//{
//	for (int i = 0; i < goalList.size(); i++) {
//		map[goalList[i].x][goalList[i].y] = 2;
//	}
//	return;
//}

bool GameController::IsinMapNow()
{
	if (pushBoxGame.getX_userPosition() < pushBoxGame.getRow() && pushBoxGame.getX_userPosition() > 0 && pushBoxGame.getY_userPosition() < pushBoxGame.getCol() && pushBoxGame.getY_userPosition() > 0)
	{
		return true;
	}
	return false;
}
bool GameController::IsinMapNow(int dy, int dx)
{
	if ((dx < pushBoxGame.getCol() && dx >0 && dy < pushBoxGame.getCol() && dy > 0))
	{
		return true;
	}
	return false;
}

bool GameController::CheckPosition(Coordinates userposition)
{
	if (!IsinMapNow())
	{
		return false;
	}

	int dx = pushBoxGame.getX_userPosition() + userposition.x;
	int dy = pushBoxGame.getY_userPosition() + userposition.y;

	if (!IsinMapNow(dy, dx))
	{
		return false;
	};

	if (pushBoxGame.map[dy][dx] == 1)
	{
		return false;
	}
	return true;
}

void GameController::move(Coordinates userposition)
{

	int curX = pushBoxGame.getX_userPosition();
	int curY = pushBoxGame.getY_userPosition();

	int nextX = curX + userposition.x;
	int nextY = curY + userposition.y;

	pushBoxGame.setX_userPosition(nextX);
	pushBoxGame.setY_userPosition(nextY);

	if (pushBoxGame.map[nextY][nextX] == WALL)
	{
		return;
	}

	if (pushBoxGame.map[nextY][nextX] == BOX)
	{
		int nextPosBox_X = nextX + userposition.x;
		int nextPosBox_Y = nextY + userposition.y;

		if (pushBoxGame.map[nextPosBox_Y][nextPosBox_X]
			== BOX || pushBoxGame.map[nextPosBox_Y][nextPosBox_X] == WALL)
		{
			return;
		}

		pushBoxGame.map[curY][curX] = EMPTY;
		pushBoxGame.map[nextY][nextX] = PLAYER;
		pushBoxGame.map[nextPosBox_Y][nextPosBox_X] = BOX;
		return;
	}
	pushBoxGame.map[curY][curX] = EMPTY;
	pushBoxGame.map[nextY][nextX] = PLAYER;

}


//void PushBoxGame::showMap()
//{
//	cout << endl;
//	for (int i = 0; i < MAX_SIZE_ROW; i++) {
//		for (int j = 0; j < MAX_SIZE_COL; j++) {
//			cout << map[i][j];
//		}
//		cout << endl;
//	}
//
//	cout << "position: ( " << position.first << " , " << position.second << " )" << endl;
//
//	return;
//}
//void PushBoxGame::showWithPlayer()
//{
//	int temp = map[getPosition().first][getPosition().second];
//	map[getPosition().first][getPosition().second] = 8;
//	//player will be shown by 8;
//	showMap();
//	map[getPosition().first][getPosition().second] = temp;
//	return;
//}
//
//void PushBoxGame::showGoalList()
//{
//	for (int i = 0; i < goalList.size(); i++) {
//		cout << "goalList[" << i << "]  ( " << goalList[i].x << " , " << goalList[i].y << " )" << endl;
//	}
//	return;
//}
