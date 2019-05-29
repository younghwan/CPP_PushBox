#include "PushBoxGame.h"

PushBoxGame::PushBoxGame()
{
	ifstream in;
	in.open("level1.txt");
	in >> position.first >> position.second;

	map = new int* [MAX_SIZE_ROW];
	for (int i = 0; i < MAX_SIZE_ROW; i++) {
		map[i] = new int[MAX_SIZE_COL];
		for (int j = 0; j < MAX_SIZE_COL; j++) {
			in >> map[i][j];
		}
	}
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

void PushBoxGame::readMap()
{
	ifstream in;
	string a = "level";
	string b = to_string(getLevel());
	string c = ".txt";
	in.open(a + b + c);
	in >> position.first >> position.second;

	for (int i = 0; i < MAX_SIZE_ROW; i++) {
		for (int j = 0; j < MAX_SIZE_COL; j++) {
			in >> map[i][j];
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