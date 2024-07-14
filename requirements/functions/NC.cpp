#include "../includes/NC.hpp"

extern "C" {
    NC *createNCInstance() {
        return new NC();
    }
}


NC::NC(void) : Library() {
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

    this->win = newwin(1000, 1000, 0, 0);
    refresh();
}

NC::NC(const NC &original) {
    *this = original;
}

NC& NC::operator=(const NC& original) {
    if (this != &original)
    {
        this->height = original.height;
        this->width = original.width;
        this->keyCode = original.keyCode;
        this->mode = original.mode;
        this->prevMode = original.prevMode;
        this->winH = original.winH;
        this->winW = original.winW;
        this->win = original.win;
    }
    return *this;
}

NC::~NC() {
    endwin();
}


void NC::display() {
    wrefresh(this->win);
}

void NC::input() {
    switch (getch())
	{
		case '1':
			this->keyCode = SFMLCODE;
			break;
		case '3':
			this->keyCode = GLCODE;
			break;
		case 27:
			this->keyCode = QUIT;
			break;
	}
}

void NC::update() {
    this->input();
    this->display();
}