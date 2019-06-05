#pragma once

#include "CommonDefinition.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include "curses.h"

using namespace std;

class PushBoxGame
{
private:
	int rowMax = 10;
	int colMax = 10;
	int level = 1;
	int step = 0;
	int push = 0;
	Coordinates userPosition;
	vector<Coordinates> goalList;
	vector<vector<int> > records;
	
public:
	char** map;

	PushBoxGame() {
		ifstream in;
		in.open("level1.txt");
		int a, b;
		in >> a >> b;
		setX_userPosition(a);
		setY_userPosition(b);
		map = new char* [rowMax];
		for (int i = 0; i < rowMax; i++) {
			int temp;
			map[i] = new char[colMax];
			for (int j = 0; j < colMax; j++) {
				in >> temp;
				map[i][j] = temp;
				if (temp == 3) {
					goalList.push_back(Coordinates(i, j));
				}
			}
		}
	};
	int getLevel()
	{
		return level;
	}
	void setLevel(int input)
	{
		this->level = input;
		return;
	}
	Coordinates getUserPosition()
	{
		return userPosition;
	}
	void setUserPosition(Coordinates input)
	{
		userPosition.x = input.x;
		userPosition.y = input.y;
		return;
	}
	int getStep()
	{
		return step;
	}
	void setStep(const int& input)
	{
		this->step = input;
		return;
	};
	int getPush()
	{
		return push;
	}
	void setPush(const int& input)
	{
		this->push = input;
		return;
	}
	void setX_userPosition(const int& input)
	{
		this->userPosition.x = input;
	}
	void setY_userPosition(const int& input)
	{
		this->userPosition.y = input;
	}
	int getX_userPosition()
	{
		return userPosition.x;
	}
	int getY_userPosition()
	{
		return userPosition.y;
	}
	int getRow() {
		return rowMax;
	}
	int getCol() {
		return colMax;
	}
	vector<Coordinates> getGoalList() {
		return goalList;
	}
	vector<vector<int> > getRecords() {
		return records;
	}
	void addRecords(vector<int> input) {
		records.push_back(input);
	}
	void pushBoxGameInit() {
		ifstream in;
		in.open("level1.txt");
		int a, b;
		in >> a >> b;
		setX_userPosition(a);
		setY_userPosition(b);
		map = new char* [rowMax];
		for (int i = 0; i < rowMax; i++) {
			int temp;
			map[i] = new char[colMax];
			for (int j = 0; j < colMax; j++) {
				in >> temp;
				map[i][j] = temp;
				if (temp == 3) {
					goalList.push_back(Coordinates(i, j));
				}
			}
		}
	}

	void readMap()
	{
		ifstream in;
		string a = "level";
		string b = to_string(getLevel());
		string c = ".txt";
		in.open(a + b + c);
		in >> userPosition.x >> userPosition.y;

		goalList.clear();
		for (int i = 0; i < rowMax; i++) {
			int temp;
			for (int j = 0; j < colMax; j++) {
				in >> temp;
				map[i][j] = temp;
				if (temp == 3) {
					goalList.push_back(Coordinates(i, j));
				}
			}
		}
		return;
	}
	
};