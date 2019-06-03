#include "PushBoxGame.h"

int main()
{
	WINDOW *win1, *win2, *win3, *win4, *win5;

	initscr();
	resize_term(35, 95);
	start_color();
	curs_set(0);
	noecho();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	border('*', '*', '*', '*', '*', '*', '*', '*');
	refresh();


	win5 = newwin(27, 70, 4, 2);
	win1 = newwin(3, 15, 8, 75);
	win2 = newwin(3, 15, 12, 75);
	win3 = newwin(3, 15, 16, 75);
	win4 = newwin(3, 15, 20, 75);
	wbkgd(win1, COLOR_PAIR(1));
	wattron(win1, COLOR_PAIR(1));
	wbkgd(win2, COLOR_PAIR(1));
	wattron(win2, COLOR_PAIR(1));
	wbkgd(win3, COLOR_PAIR(1));
	wattron(win3, COLOR_PAIR(1));
	wbkgd(win4, COLOR_PAIR(1));
	wattron(win4, COLOR_PAIR(1));

	mvwprintw(win1, 1, 1, "level: ");
	mvwprintw(win1, 1, 8, " "); //레벨변수 넣기
	mvwprintw(win2, 1, 1, "move: ");
	mvwprintw(win2, 1, 8, " "); //이동변수 넣기
	mvwprintw(win3, 1, 1, "goal: ");
	mvwprintw(win3, 1, 8, " "); //넣은횟수 넣기
	mvwprintw(win4, 1, 1, "time: ");
	mvwprintw(win4, 1, 8, " "); //이동변수 넣기
	wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(win4, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(win5, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(win1);
	wrefresh(win2);
	wrefresh(win3);
	wrefresh(win4);
	wrefresh(win5);
	getch();
	delwin(win1);
	endwin();
	return 0;
}
