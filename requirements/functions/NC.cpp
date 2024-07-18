#include "../includes/NC.hpp"

extern "C" {
    NC *createNCInstance() {
        return new NC();
    }
}


NC::NC(void) : Library() {
	initscr();
	keypad(stdscr, TRUE);

    this->win = newwin(LINES, COLS, 0, 0);
    this->cols = COLS;
    this->lines = LINES;

    box(this->win, 0, 0);
    wrefresh(this->win);
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
    static bool pause = false;

    if (this->cols != COLS || this->lines != LINES)
    {
        this->cols = COLS;
        this->lines = LINES;

        wclear(this->win);
        resize_term(LINES, COLS);
    }

    if (this->mode == PAUSE)
    {
        if (!pause)
        {
            pause = true;
            wclear(this->win);
        }
        mvwprintw(this->win, LINES / 2, COLS / 2, "PAUSE");
    }
    else
    {
        if (pause)
        {
            pause = false;
            wclear(this->win);
        } 
        this->drawMap();
    }
    wrefresh(this->win);
}

void NC::drawMap() {
    box(this->win, 0, 0);

    for (size_t i = 0; i < this->map.size(); i++)
    {
        for (size_t j = 0; j < this->map[i].size(); j++)
        {
            if (this->map[i][j] == 'S')
                mvwaddch(this->win, i + 1, j + 1, 'S');
        }
    }
}

void NC::input() {
    static bool pause = false;

    switch (getch())
	{
        case 27:
            this->keyCode = QUIT;
			break;

        case 32:
            if (!pause)
                this->keyCode = PAUSE;
            else
                this->keyCode = GAME;
            pause = !pause;
            break;

		case '1':
			this->keyCode = SFMLCODE;
			break;

		case '3':
			this->keyCode = SDLCODE;
			break;

        case 'W':
        case 'w':
            this->keyCode = UP;
            break;
        
        case 'S':
        case 's':
            this->keyCode = DOWN;
            break;
        
        case 'A':
        case 'a':
            this->keyCode = LEFT;
            break;
        
        case 'D':
        case 'd':
            this->keyCode = RIGHT;
            break;

        default:
            break;
	}
}

void NC::pause() {
    if (this->mode == PAUSE)
        this->mode = GAME;
    else
        this->mode = PAUSE;
}

void NC::update() {
    this->display();
    this->input();
}