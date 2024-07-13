#include "../includes/SFML.hpp"

extern "C" {
    SFML *createSFMLInstance(void) {
        return new SFML();
    }
}

SFML::SFML(void) : Library() {
    this->win = new sf::RenderWindow(sf::VideoMode(this->winW, this->winH), "Nibbler SFML", sf::Style::Close);
    if (!errorQuitLibWithObj(this->win, "Error: Could not create SFML window", this))
        return;
    this->isWindowOpen = true;
}

SFML::SFML(const SFML &original) {
    *this = original;
}

SFML &SFML::operator=(const SFML &original) {
    if (this != &original)
    {
        this->height = original.height;
        this->width = original.width;
        this->keyCode = original.keyCode;
        this->mode = original.mode;
        this->prevMode = original.prevMode;
        this->isWindowOpen = original.isWindowOpen;
        this->winH = original.winH;
        this->winW = original.winW;
        this->win = original.win;
    }
    return *this;
}

SFML::~SFML() {
    if (this->win)
    {
        this->win->close();
        
    }
}

void SFML::closeWindow() {
    if (this->win)
    {
        this->win->close();
        this->isWindowOpen = false;
    }
}

void SFML::openWindow() {
    if (this->win)
    {
        this->win->create(sf::VideoMode(this->winW, this->winH), "Nibbler SFML", sf::Style::Close);
        this->isWindowOpen = true;
    }
}

void SFML::display() {
    this->win->clear();

    if (this->win && !this->isWindowOpen)
        this->openWindow();

    this->win->display();
}

void SFML::drawArea() {
}

void SFML::input() {
    sf::Event event;

    while (this->win->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                this->keyCode = QUIT;
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    this->keyCode = QUIT;
                }
                else if (event.key.code == sf::Keyboard::Return)
                {
                    return;
                }
                else if (event.key.code == sf::Keyboard::Space)
                {
                    return;
                }
                else if (event.key.code == sf::Keyboard::Num2)
                {
                    this->keyCode = SDLCODE;
                }
                else if (event.key.code == sf::Keyboard::Num3)
                {
                    this->keyCode = GLCODE;
                }
                else if (event.key.code == sf::Keyboard::W)
                {
                    return;
                }
                else if (event.key.code == sf::Keyboard::A)
                {
                    return;
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    return;
                }
                else if (event.key.code == sf::Keyboard::D)
                {
                    return;
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    return;
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    return;
                }
                break;

            default:
                break;
        }
    }
}


void SFML::update(void) {
    this->input();
    this->display();
}