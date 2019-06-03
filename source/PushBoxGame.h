#pragma once

#include "CommonDefinition.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <time.h>
#include "curses.h"

using namespace std;

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
	int** map;
	COORDINATE position;
	vector<COORDINATE> goalList;
	vector<vector<int>> records;
	
public:
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
	void move(int);
};