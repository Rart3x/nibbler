#include "../includes/SFML.hpp"

extern "C" {
    SFML *createSFMLInstance(void) {
        return new SFML();
    }
}

SFML::SFML(void) : Library() {
    this->win = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Nibbler SFML", sf::Style::Close);
    if (!errorQuitLibWithObj(this->win, "Error: Could not create SFML window", this))
        return;
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
        this->win = original.win;
    }
    return *this;
}

SFML::~SFML() {
    if (this->win)
    {
        delete this->win;
    }
}

void SFML::display() {
    this->win->clear();
    this->drawMap();
    this->win->display();
}

void SFML::drawMap() {
    sf::RectangleShape rect(sf::Vector2f(WIDTH / this->map[0].size(), HEIGHT / this->map.size()));

    for (size_t i = 0; i < this->map.size(); i++)
    {
        for (size_t j = 0; j < this->map[i].size(); j++)
        {
            if (this->map[i][j] == '0')
                rect.setFillColor(sf::Color::White);
            else if (this->map[i][j] == '1')
                rect.setFillColor(sf::Color::Black);

            rect.setPosition(j * (WIDTH / this->map[0].size()), i * (HEIGHT / this->map.size()));
            this->win->draw(rect);
        }
    }
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
                    this->keyCode = NCCODE;
                }
                else if (event.key.code == sf::Keyboard::Num3)
                {
                    this->keyCode = GLCODE;
                }
                else if (event.key.code == sf::Keyboard::W)
                {
                    this->keyCode = UP;
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    this->keyCode = DOWN;
                }
                else if (event.key.code == sf::Keyboard::A)
                {
                    this->keyCode = LEFT;
                }
                else if (event.key.code == sf::Keyboard::D)
                {
                    this->keyCode = RIGHT;
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