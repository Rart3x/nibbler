#include "../includes/SFML.hpp"

extern "C" {
    SFML *createSFMLInstance(void) {
        return new SFML();
    }
}


SFML::SFML(void) : Library() {
    this->running = false;
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

    this->win = new sf::RenderWindow(sf::VideoMode(this->height, this->width), "Nibbler SFML");
    if (!this->win) {
        std::cerr << "Error: Could not create SFML window" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->running = true;

    while (this->running) {
        this->input();
        this->win->display();
    }
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
                } else if (event.key.code == sf::Keyboard::Num1) {
                    this->libCode = 0;
                    this->running = false;
                } else if (event.key.code == sf::Keyboard::Num2) {
                    this->libCode = 1;
                    this->running = false;
                } else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
                    return;
                } else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                    return;
                } else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
                    return;
                }
                break;

            default:
                break;
        }
    }
}

size_t SFML::getLibCode(void) const {
    return this->libCode;
}

void SFML::setWindowSize(int h, int w) {
    this->height = h;
    this->width = w;
}