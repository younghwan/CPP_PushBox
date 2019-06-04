#pragma once

#include "CommonDefinition.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

enum
{
	EMPTY = 0,
	WALL = 1,
	BOX = 2,
	HOLE = 3,
	BOUND =4,
	PLAYER =5
};


struct Position
{
    int x,y;
};

class PushBoxGame
{
private:
	const int MAX_SIZE_ROW = 10;
	const int MAX_SIZE_COL = 10;
	const int FINALLEVEL = 5;
	int level = 1;
	int step = 0;
	int push = 0;
	clock_t startTimer;
	clock_t endTimer;
	COORDINATE position;
	vector<COORDINATE> goalList;
	vector<vector<int> > records;
	Position userposition;
	
public:
	char** map;

	PushBoxGame();
	int getLevel();
	void setLevel(int);
	COORDINATE getPosition();
	void setPosition(COORDINATE);
	int getStep();
	void setStep(int);
	int getPush();
	void setPush(int);
	void readMap();
	void showMap();
	bool isSuccess();
	void showWithPlayer();
	void showGoalList();
	void afterProcess();
	void testGoToLevel2();
	void move(Position userposition);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	bool CheckPosition(Position movePos);
	bool IsinMapNow() const;
    bool IsinMapNow(int dy,int dx) const;
	
};