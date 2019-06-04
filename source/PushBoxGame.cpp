#include "PushBoxGame.h"

PushBoxGame::PushBoxGame()
{
	ifstream in;
	in.open("level1.txt");
	in >> position.first >> position.second;

	map = new char* [MAX_SIZE_ROW];
	for (int i = 0; i < MAX_SIZE_ROW; i++) {
		int temp;
		map[i] = new char[MAX_SIZE_COL];
		for (int j = 0; j < MAX_SIZE_COL; j++) {
			in >> temp;
			map[i][j] = temp;
			if (temp == 3) {
				goalList.push_back(COORDINATE(i, j));
			}
		}
	}
	startTimer = clock();
}

int PushBoxGame::getLevel()
{
	return level;
}

void PushBoxGame::setLevel(int input)
{
	level = input;
	return;
}

COORDINATE PushBoxGame::getPosition()
{
	return position;
}

void PushBoxGame::setPosition(COORDINATE input)
{
	position.first = input.first;
	position.second = input.second;
}

int PushBoxGame::getStep()
{
	return step;
}

void PushBoxGame::setStep(int input)
{
	step = input;
	return;
}

int PushBoxGame::getPush()
{
	return push;
}

void PushBoxGame::setPush(int input)
{
	push = input;
	return;
}

void PushBoxGame::readMap()
{
	ifstream in;
	string a = "level";
	string b = to_string(getLevel());
	string c = ".txt";
	in.open(a + b + c);
	in >> position.first >> position.second;

	goalList.clear();
	for (int i = 0; i < MAX_SIZE_ROW; i++) {
		int temp;
		for (int j = 0; j < MAX_SIZE_COL; j++) {
			in >> temp;
			map[i][j] = temp;
			if (temp == 3) {
				goalList.push_back(COORDINATE(i, j));
			}
		}
	}
	return;
}

void PushBoxGame::showMap()
{
	cout << endl;
	for (int i = 0; i < MAX_SIZE_ROW; i++) {
		for (int j = 0; j < MAX_SIZE_COL; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

	cout << "position: ( " << position.first << " , " << position.second << " )" << endl;

	return;
}

bool PushBoxGame::isSuccess()
{
	for (int i = 0; i < goalList.size(); i++) {
		int x = goalList[i].first;
		int y = goalList[i].second;
		if (map[x][y] == 2) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

void PushBoxGame::showWithPlayer()
{
	int temp = map[getPosition().first][getPosition().second];
	map[getPosition().first][getPosition().second] = 8;
	//player will be shown by 8;
	showMap();
	map[getPosition().first][getPosition().second] = temp;
	return;
}

void PushBoxGame::showGoalList()
{
	for (int i = 0; i < goalList.size(); i++) {
		cout << "goalList[" << i << "]  ( " << goalList[i].first << " , " << goalList[i].second << " )" << endl;
	}
	return;
}

void PushBoxGame::afterProcess()
{
	showWithPlayer();
	if (isSuccess()) {
		endTimer = clock();
		vector<int> rec;
		rec.push_back(step);
		rec.push_back(push);
		rec.push_back((int)(startTimer-endTimer));
		records.push_back(rec);
		if (getLevel() == FINALLEVEL) {
			cout << "##### Congraturation! You complete final level #####" << endl;
		}
		else {
			cout << "############## SUCCESS ##############" << endl;
			setLevel(getLevel() + 1);
			setStep(0);
			setPush(0);
			readMap();
			startTimer = clock();
		}
	}
	return;
}

void PushBoxGame::testGoToLevel2()
{
	for (int i = 0; i < goalList.size(); i++) {
		map[goalList[i].first][goalList[i].second] = 2;
	}
	return;
}

bool PushBoxGame::IsinMapNow() const
{
    if(userposition.x < MAX_SIZE_ROW && userposition.x > 0 && userposition.y < MAX_SIZE_COL &&userposition.y > 0)
    {
        return true;
    }
    return false;
}

bool PushBoxGame::IsinMapNow(int dy,int dx) const
{
    if(dx < MAX_SIZE_ROW && dx >0 && dy < MAX_SIZE_COL && dy > 0)
    {
        return true;    
    }
    return false;
}

bool PushBoxGame::CheckPosition(Position userposition)
{
	if(!IsinMapNow())
    {
        return false;
    }

	int dx = getX() + userposition.x;
    int dy = getY() + userposition.y;

	if(!IsinMapNow(dy,dx))
    {
        return false;
    };

	if(map[dy][dx]==1)
    {
        return false;
    }
	return true;
}

void PushBoxGame::move(Position userposition)
{

	int curX = getX();
    int curY = getY();

	int nextX = curX + userposition.x;
    int nextY = curY + userposition.y;

	setX(nextX);
    setY(nextY);

	if(map[nextY][nextX] == WALL )
	{
		return;
	}

	if(map[nextY][nextX] == BOX)
	{
		int nextPosBox_X = nextX + userposition.x;
		int nextPosBox_Y = nextY + userposition.y;

		if(map[nextPosBox_Y][nextPosBox_X]
		==BOX ||map[nextPosBox_Y][nextPosBox_X] == WALL )
		{
			return;
		}

		map[curY][curX] = EMPTY;
		map[nextY][nextX] = PLAYER;
		map[nextPosBox_Y][nextPosBox_X] = BOX;
		return;
	}
	map[curY][curX] = EMPTY;
	map[nextY][nextX] = PLAYER;

}

void PushBoxGame::setX(int input)
{
	userposition.x = input;
}

void PushBoxGame::setY(int input)
{
	userposition.y = input;
}

int PushBoxGame::getX()
{
	return userposition.x;
}

int PushBoxGame::getY()
{
	return userposition.y;
}