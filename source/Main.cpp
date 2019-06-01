#include "PushBoxGame.h"

int main()
{
	PushBoxGame Game;
	Game.showMap();
	Game.showWithPlayer();
	Game.showMap();
	Game.showGoalList();
	Game.testGoToLevel2();
	Game.afterProcess();

	while (true) {
		if (_kbhit()) {
			int key = _getch();
			if (_kbhit()) {
				key = _getch();
				//key manual
				//up: 72, right: 77, down:80, left: 75
				Game.move(key);
				cout << key << endl;
			}
		}
	}
	
	return 0;
}
