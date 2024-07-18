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

    if (this->mode == PAUSE)
        this->displayPause();
    else
        this->drawMap();

    this->win->display();
}

void SFML::displayPause() {
    sf::Font font;
    sf::Text pauseText;

    if (!errorQuitLibWithBool(font.loadFromFile(ARIAL), "Error: Could not load font", this))
        return;

    pauseText.setFont(font);
    pauseText.setString("Pause");
    pauseText.setCharacterSize(72);
    pauseText.setFillColor(sf::Color::White);

    int windowWidth = this->win->getSize().x;
    int windowHeight = this->win->getSize().y;

    float textWidth = pauseText.getLocalBounds().width;
    float textHeight = pauseText.getLocalBounds().height;
    float centerX = windowWidth / 2.0f - textWidth / 2.0f;
    float centerY = windowHeight / 2.0f - textHeight / 2.0f;

    pauseText.setPosition(centerX, centerY);
    this->win->draw(pauseText);
}

void SFML::drawMap() {
    // sf::RectangleShape rect(sf::Vector2f(WIDTH / this->map[0].size(), HEIGHT / this->map.size()));

    // for (size_t i = 0; i < this->map.size(); i++)
    // {
    //     for (size_t j = 0; j < this->map[i].size(); j++)
    //     {
    //         if (this->map[i][j] == '0')
    //             rect.setFillColor(sf::Color::White);
    //         else if (this->map[i][j] == '1')
    //             rect.setFillColor(sf::Color::Black);

    //         rect.setPosition(j * (WIDTH / this->map[0].size()), i * (HEIGHT / this->map.size()));
    //         this->win->draw(rect);
    //     }
    // }
}


void SFML::input() {
    sf::Event event;

    static bool pause = false;

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
                    if (!pause)
                        this->keyCode = PAUSE;
                    else
                        this->keyCode = GAME;
                    pause = !pause;
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

void SFML::pause() {
    if (this->mode == PAUSE)
        this->mode = GAME;
    else
        this->mode = PAUSE;
}

void SFML::update(void) {
    this->display();
    this->input();
}