#include "../includes/SFML.hpp"

extern "C" {
    SFML *createSFMLInstance(void) {
        return new SFML();
    }
}


SFML::SFML(void) {
    this->running = false;
}


SFML::~SFML() {
    delete this->win;
}


void SFML::display() {

    this->win = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Nibbler SFML");
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
                this->running = false;
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    this->running = false;
                }
                break;

            default:
                break;
        }
    }
}