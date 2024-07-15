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

    this->win = newwin(HEIGHT, WIDTH, 0, 0);
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
    this->drawMap();
    wrefresh(this->win);
}

void NC::drawMap() {
    for (size_t i = 0; i < this->map.size(); i++)
    {
        for (size_t j = 0; j < this->map[i].size(); j++)
        {
            if (i == 0 || i == this->map.size() - 1)
            {
                if (j == 0 || j == this->map[i].size() - 1)
                {
                    if (i == 0 && j == 0)
                        mvwaddch(this->win, i, j, 'x');
                    else if (i == this->map.size() - 1 && j == 0)
                        mvwaddch(this->win, i, j, 'x');
                    else if (i == 0 && j == this->map[i].size() - 1)
                        mvwaddch(this->win, i, j, 'x');
                    else if (i == this->map.size() - 1 && j == this->map[i].size() - 1)
                        mvwaddch(this->win, i, j, 'x');
                    else
                        mvwaddch(this->win, i, j, ACS_HLINE);
                }
            }
            else if (j == 0 || j == this->map[i].size() - 1)
                mvwaddch(this->win, i, j, ACS_VLINE);
            else
            {
                if (this->map[i][j] == '0')
                    mvwaddch(this->win, i, j, ' ');
                else if (this->map[i][j] == '1')
                    mvwaddch(this->win, i, j, ACS_HLINE);
            }
        }
    }
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

void NC::update() {
    this->input();
    this->display();
}