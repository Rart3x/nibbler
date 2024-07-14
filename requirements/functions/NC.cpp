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

    this->win = newwin(50, 50, 0, 0);
    this->update();
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
        this->win = original.win;
    }
    return *this;
}

NC::~NC() {
    delwin(this->win);
    endwin();
}


void NC::display() {
    wclear(this->win);
    wrefresh(this->win);
}

void NC::input() {
    switch (getch())
	{
        case 27:
			this->keyCode = QUIT;
			break;

		case '1':
			this->keyCode = SFMLCODE;
			break;

		case '3':
			this->keyCode = GLCODE;
			break;

        case 'W':
            this->keyCode = UP;
            break;
        
        case 'S':
            this->keyCode = DOWN;
            break;
        
        case 'A':
            this->keyCode = LEFT;
            break;
        
        case 'D':
            this->keyCode = RIGHT;
            break;

        default:
            break;
	}
}

void NC::update() {
    this->input();
    this->display();
}