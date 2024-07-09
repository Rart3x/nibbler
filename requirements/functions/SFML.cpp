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
    this->win = NULL;
    this->winH = HEIGHT;
    this->winW = WIDTH;
}


SFML::~SFML() {
    if (this->win)
        delete this->win;
}


void SFML::closeWindow() {
    if (this->win)
    {
        this->win->close();
        delete this->win;
        this->win = NULL;
    }
}


void SFML::display() {
    if (this->win)
        this->closeWindow();
    this->win = new sf::RenderWindow(sf::VideoMode(this->winW, this->winH), "Nibbler SFML");
    if (!errorQuitLibWithObj(this->win, "Error: Could not create SFML window", this))
        return;

    this->running = true;

    while (this->running) {
        this->win->clear();
        this->input();

        if (this->mode == 0)
            this->displayMenu();
        else if (this->mode == 1)
            this->displayGame();
        else if (this->mode == 2)
            this->displayPause();
        
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
    sf::Vector2f quitButtonSize(200, 50);
    sf::Vector2f startButtonSize(200, 50);

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
    this->drawTitle("Nibbler", sf::Color::White);
    this->win->draw(pauseText);
}


void SFML::drawButton(std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    sf::Font            font;
    sf::RectangleShape  rectangle(size);
    sf::Text            buttonText;

    rectangle.setFillColor(color);
    rectangle.setPosition(position);

    if (!errorQuitLibWithBool(font.loadFromFile(ARIAL), "Error: Could not load font", this))
        return;

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(sf::Color::Black);

    float textWidth = buttonText.getLocalBounds().width;
    float textHeight = buttonText.getLocalBounds().height;
    float centerX = position.x + size.x / 2;
    float centerY = position.y + size.y / 2;

    buttonText.setPosition(centerX - textWidth / 2, centerY - textHeight);

    this->win->draw(rectangle);
    this->win->draw(buttonText);
}


void SFML::drawTitle(std::string text, sf::Color color) {
    sf::Font        font;
    sf::Vector2f    localPosition;
    sf::Text        title;

    if (!errorQuitLibWithBool(font.loadFromFile(SCIENCE), "Error: Could not load font", this))
        return;

    title.setFont(font);
    title.setString(text);
    title.setCharacterSize(48);
    title.setFillColor(color);

    localPosition.x = this->winW / 2.0f - title.getGlobalBounds().width / 2.0f;
    localPosition.y = 10;

    title.setPosition(localPosition);

    this->win->draw(title);
}


void SFML::input() {
    sf::Event event;

    while (this->win->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                this->libCode = QUIT;
                this->running = false;
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    this->libCode = QUIT;
                    this->running = false;
                }
                else if (event.key.code == sf::Keyboard::Return)
                {
                    if (this->selectedButton == 0)
                    {
                        this->mode = GAME;
                        this->prevMode = GAME;
                    }
                    else
                    {
                        this->libCode = QUIT;
                        this->running = false;
                    }
                }
                else if (event.key.code == sf::Keyboard::Space)
                {
                    if (this->mode == GAME)
                    {
                        this->prevMode = this->mode;
                        this->mode = PAUSE;
                    }
                    else if (this->mode == PAUSE && this->prevMode == GAME)
                        this->mode = GAME;
                }
                else if (event.key.code == sf::Keyboard::Num2)
                {
                    if (this->mode == GAME || this->mode == PAUSE)
                    {
                        this->libCode = 1;
                        this->running = false;
                    }
                }
                else if (event.key.code == sf::Keyboard::Num3)
                {
                    if (this->mode == GAME || this->mode == PAUSE)
                    {
                        this->libCode = 2;
                        this->running = false;
                    }
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
                    if (this->selectedButton == 1)
                        this->selectedButton = 0;
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    if (this->selectedButton == 0)
                        this->selectedButton = 1;
                }
                break;

            case sf::Event::Resized:
                this->setWinSize(event.size.height, event.size.width);
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

void SFML::setLibCode(int code) {
    this->libCode = code;
}

void SFML::setRunning() {
    this->running = !this->running;
}

void SFML::setWinSize(int h, int w) {
    this->winH = h;
    this->winW = w;
}