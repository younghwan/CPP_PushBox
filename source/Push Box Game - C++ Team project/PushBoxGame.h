#pragma once

#include "CommonDefinition.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class PushBoxGame
{
private:
	const int MAX_SIZE_ROW = 10;
	const int MAX_SIZE_COL = 10;
	const int finalLevel = 5;
	int level = 1;
	int step = 0;
	int push = 0;
	int** map;
	COORDINATE position;
	
public:
	PushBoxGame();
	int getLevel();
	void setLevel(int);
	void readMap();
	void showMap();

};