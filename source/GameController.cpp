#include "GameController.h"

void GameController::gameInitialize() {
	setlocale(LC_ALL, "");
	initscr();
	resize_term(27, 65);
	start_color();
	curs_set(0);
	noecho();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE); //EMPTY color
	init_pair(3, COLOR_WHITE, COLOR_MAGENTA); //BLOCK color
	init_pair(4, COLOR_WHITE, COLOR_YELLOW); //BOX color
	init_pair(5, COLOR_WHITE, COLOR_GREEN); //GOAL color
	init_pair(6, COLOR_WHITE, COLOR_RED); //PLAYER color
	mvprintw(2, 20, "P U S H    B O X    G A M E");
	mvprintw(25, 13, "Press \'r\' to reset ");
	refresh();

	gameBoard = newwin(19, 40, 6, 2);
	levelBoard = newwin(3, 13, 8, 45);
	stepBoard = newwin(3, 13, 12, 45);
	pushBoard = newwin(3, 13, 16, 45);
	resetBoard = newwin(3, 13, 20, 45);
	wbkgd(levelBoard, COLOR_PAIR(1));
	wattron(levelBoard, COLOR_PAIR(1));
	wbkgd(stepBoard, COLOR_PAIR(1));
	wattron(stepBoard, COLOR_PAIR(1));
	wbkgd(pushBoard, COLOR_PAIR(1));
	wattron(pushBoard, COLOR_PAIR(1));
	wbkgd(resetBoard, COLOR_PAIR(1));
	wattron(resetBoard, COLOR_PAIR(1));

	mvwprintw(levelBoard, 1, 1, "Level: ");
	mvwprintw(levelBoard, 1, 8, " ");
	mvwprintw(stepBoard, 1, 1, "Move: ");
	mvwprintw(stepBoard, 1, 8, " ");
	mvwprintw(pushBoard, 1, 1, "Push: ");
	mvwprintw(pushBoard, 1, 8, " ");
	mvwprintw(resetBoard, 1, 1, "Reset: ");
	mvwprintw(resetBoard, 1, 8, " ");
	wborder(levelBoard, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(stepBoard, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(pushBoard, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(resetBoard, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(gameBoard, '|', '|', '-', '-', '+', '+', '+', '+');

	wrefresh(levelBoard);
	wrefresh(stepBoard);
	wrefresh(pushBoard);
	wrefresh(resetBoard);
	wrefresh(gameBoard);
}

void GameController::gameDelete() {
	delwin(levelBoard);
	delwin(stepBoard);
	delwin(pushBoard);
	delwin(resetBoard);
	delwin(gameBoard);
	endwin();
	return;
}

bool GameController::IsinMapNow()
{
	if (pushBoxGame->getX_userPos() < pushBoxGame->getRow() && pushBoxGame->getX_userPos() > 0 &&
		pushBoxGame->getY_userPos() < pushBoxGame->getCol() && pushBoxGame->getY_userPos() > 0)
	{
		return true;
	}
	return false;
}
bool GameController::IsinMapNow(int dy, int dx)
{
	if ((dx < pushBoxGame->getCol() && dx >0 && dy < pushBoxGame->getCol() && dy > 0))
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

	int dx = pushBoxGame->getX_userPos() + userposition.x;
	int dy = pushBoxGame->getY_userPos() + userposition.y;

	if (!IsinMapNow(dy, dx))
	{
		return false;
	};

	if (pushBoxGame->getMap(dy, dx) == 1)
	{
		return false;
	}
	return true;
}

void GameController::setGoalPos(vector<Coordinates> goalList)
{
	for(int i = 0; i<goalList.size(); i++)
	{
		int goalX = goalList[i].x;
		int goalY = goalList[i].y;

		if(pushBoxGame->getMap(goalY,goalX) == EMPTY)
		{
			pushBoxGame->setMap(Coordinates(goalY, goalX), GOAL);
		}
	}	
}
void GameController::move(Coordinates userposition)
{
	pushBoxGame->addStep();
	
	int curX = pushBoxGame->getX_userPos();
	int curY = pushBoxGame->getY_userPos();

	int nextX = curX + userposition.x;
	int nextY = curY + userposition.y;

	if (pushBoxGame->getMap(nextY, nextX) == WALL)
	{
		return;
	}


	//BOX를 밀때
	if (pushBoxGame->getMap(nextY, nextX) == BOX)
	{
		int nextPosBox_X = nextX + userposition.x;
		int nextPosBox_Y = nextY + userposition.y;

		if (pushBoxGame->getMap(nextPosBox_Y, nextPosBox_X)
			== BOX || pushBoxGame->getMap(nextPosBox_Y, nextPosBox_X) == WALL)
		{
			return;
		}

		pushBoxGame->setMap(Coordinates(curY, curX), EMPTY);
		pushBoxGame->setMap(Coordinates(nextY, nextX), PLAYER);
		pushBoxGame->setMap(Coordinates(nextPosBox_Y, nextPosBox_X), BOX);
		pushBoxGame->setUserPos(Coordinates(nextX, nextY));
		pushBoxGame->addPush();
		return;
	}
	pushBoxGame->setMap(Coordinates(curY, curX), EMPTY);
	pushBoxGame->setMap(Coordinates(nextY, nextX), PLAYER);
	pushBoxGame->setUserPos(Coordinates(nextX, nextY));
}

void GameController::postProcessing()
{
	setGoalPos(pushBoxGame->getGoalList());
	gameViewer->renderAll(levelBoard, stepBoard, pushBoard, resetBoard, gameBoard);

	if (isSuccess()) {
		vector<int> rec;
		rec.push_back(pushBoxGame->getStep());
		rec.push_back(pushBoxGame->getPush());
		pushBoxGame->addRecords(rec);
		if (pushBoxGame->getLevel() == FINALLEVEL) {
			//cout << "##### Congraturation! You complete final level #####" << endl;
		}
		else {
			//cout << "############## SUCCESS ##############" << endl;
			pushBoxGame->setLevel(pushBoxGame->getLevel() + 1);
			reset();
		}
	}
	return;
}

bool GameController::isSuccess()
{
	for (int i = 0; i < pushBoxGame->getGoalList().size(); i++) {
		int x = pushBoxGame->getGoalList()[i].x;
		int y = pushBoxGame->getGoalList()[i].y;
		if (pushBoxGame->getMap(y, x) == 2) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}
void GameController::goNextLevel()
{
	for (int i = 0; i < pushBoxGame->getGoalList().size(); i++) {
		int x = pushBoxGame->getGoalList()[i].x;
		int y = pushBoxGame->getGoalList()[i].y;
		pushBoxGame->setMap(Coordinates(y, x), 2);
		pushBoxGame->stepClear();
	}
	return;
}

void GameController::reset()
{
	pushBoxGame->stepClear();
	pushBoxGame->pushClear();
	pushBoxGame->readMap();
	gameViewer->renderInit(levelBoard, stepBoard, pushBoard, resetBoard);
	gameViewer->renderAll(levelBoard, stepBoard, pushBoard, resetBoard, gameBoard);
	pushBoxGame->addReset();
	return;
}