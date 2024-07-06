#include "../includes/SFML.hpp"

extern "C" {
    SFML *createSFMLInstance(void) {
        return new SFML();
    }
}


SFML::SFML(void) : Library() {
    this->mode = 0;
    this->running = false;
    this->selectedButton = 0;
    this->winH = HEIGHT;
    this->winW = WIDTH;
}


SFML::~SFML() {
    delete this->win;
}


void SFML::closeWindow() {
    if (this->win) {
        this->win->close();
        this->win = NULL;
    }
}


void SFML::display() {

    this->win = new sf::RenderWindow(sf::VideoMode(this->winW, this->winH), "Nibbler SFML");
    if (!this->win) {
        std::cerr << "Error: Could not create SFML window" << std::endl;
        this->libCode = 404;
        this->running = false;
    }

    this->running = true;

    while (this->running) {
        this->win->clear();
        this->input();

        if (this->mode == 0)
            this->displayMenu();
        else
            this->displayGame();
        
        this->win->display();
    }
}


void SFML::displayGame() {
    sf::Vector2f startButtonSize(200, 50);

    int totalButtonHeight = startButtonSize.y;

    int startY = (this->winH - totalButtonHeight) / 2;
    int startX = (this->winW - startButtonSize.x) / 2;

    sf::Vector2f startButtonPos(startX, startY);

    this->drawTitle("Nibbler", sf::Color::White);
    this->drawButton("Game", startButtonPos, startButtonSize, sf::Color::White);
}


void SFML::displayMenu() {
    sf::Vector2f startButtonSize(200, 50);
    sf::Vector2f quitButtonSize(200, 50);

    int totalButtonHeight = startButtonSize.y + quitButtonSize.y;

    int startY = (this->winH - totalButtonHeight) / 2;
    int startX = (this->winW - startButtonSize.x) / 2;

    sf::Vector2f startButtonPos(startX, startY);
    sf::Vector2f quitButtonPos(startX, startY + startButtonSize.y + HEIGHT / 20);

    this->drawTitle("Nibbler", sf::Color::White);

    if (this->selectedButton == 0)
        this->drawButton("Start", startButtonPos, startButtonSize, sf::Color::Cyan);
    else
        this->drawButton("Start", startButtonPos, startButtonSize, sf::Color::White);

    if (this->selectedButton == 1)
        this->drawButton("Quit", quitButtonPos, quitButtonSize, sf::Color::Cyan);
    else
        this->drawButton("Quit", quitButtonPos, quitButtonSize, sf::Color::White);
}


void SFML::drawButton(std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    sf::RectangleShape rectangle(size);
    rectangle.setFillColor(color);
    rectangle.setPosition(position);

    sf::Font font;
    sf::Text buttonText;

    if (!font.loadFromFile("./requirements/ressources/arial.ttf")) {
        std::cerr << "Error: Could not load font" << std::endl;
        this->libCode = 404;
        this->running = false;
    }

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(position.x + 10, position.y + 5);

    this->win->draw(rectangle);
    this->win->draw(buttonText);
}


void SFML::drawTitle(std::string text, sf::Color color) {
    sf::Font font;
    sf::Text title;

    if (!font.loadFromFile("./requirements/ressources/arial.ttf")) {
        std::cerr << "Error: Could not load font" << std::endl;
        this->libCode = 404;
        this->running = false;
    }

    title.setFont(font);
    title.setString(text);
    title.setCharacterSize(48);
    title.setFillColor(color);

    sf::Vector2f localPosition;

    localPosition.x = this->winW / 2.0f - title.getGlobalBounds().width / 2.0f;
    localPosition.y = 10;

    title.setPosition(localPosition);

    this->win->draw(title);
}



void SFML::input() {
    sf::Event event;

    while (this->win->pollEvent(event)) {
        switch (event.type) {

            case sf::Event::Closed:
                this->libCode = 404;
                this->running = false;
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    this->libCode = 404;
                    this->running = false;
                } else if (event.key.code == sf::Keyboard::Return) {
                    if (this->selectedButton == 0) {
                        this->mode = 1;
                    } else {
                        this->libCode = 404;
                        this->running = false;
                    }
                } else if (event.key.code == sf::Keyboard::Num1) {
                    this->libCode = 0;
                    this->running = false;
                } else if (event.key.code == sf::Keyboard::Num2) {
                    this->libCode = 1;
                    this->running = false;
                } else if (event.key.code == sf::Keyboard::W) {
                    return;
                } else if (event.key.code == sf::Keyboard::A) {
                    return;
                } else if (event.key.code == sf::Keyboard::S) {
                    return;
                }
                else if (event.key.code == sf::Keyboard::D) {
                    return;
                }

                if (event.key.code == sf::Keyboard::Up) {
                    if (this->selectedButton == 1)
                        this->selectedButton = 0;
                } else if (event.key.code == sf::Keyboard::Down) {
                    if (this->selectedButton == 0)
                        this->selectedButton = 1;
                }
                break;

            case sf::Event::Resized:
                this->setWinSize(event.size.height, event.size.width);
                this->win->clear();
                break;

            default:
                break;
        }
    }
}


size_t SFML::getLibCode(void) const {
    return this->libCode;
}

void SFML::setAreaSize(int h, int w) {
    this->height = h;
    this->width = w;
}

void SFML::setWinSize(int h, int w) {
    this->winH = h;
    this->winW = w;
}