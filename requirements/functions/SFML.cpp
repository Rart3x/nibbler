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

     this->win = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Nibbler SFML");
     if (!this->win) {
         std::cerr << "Error: Could not create SFML window" << std::endl;
         exit(EXIT_FAILURE);
     }

     this->running = true;

     while (this->running) {
         this->input();
         this->displayMenu();
         this->win->display();
     }
 }


 void SFML::displayMenu() {
     int totalHeight = 40 * 3;
     int windowHeight = this->win->getSize().y;
     int windowWidth = this->win->getSize().x;

     int startY = (windowHeight / 2) - (totalHeight / 2);
     int startX = (windowWidth / 2) - (totalHeight / 2);

     this->drawText("Start", startX, startY, sf::Color::White, 24);
     this->drawText("Options", startX, startY + 40, sf::Color::White, 24);
     this->drawText("Quit", startX, startY + 80, sf::Color::White, 24);
 }


 void SFML::drawText(std::string text, float x, float y, sf::Color color, float fontSize) {
     sf::Font font;
     sf::Text buttonText;

     if (!font.loadFromFile("./requirements/ressources/arial.ttf")) {
         std::cerr << "Error: Could not load font" << std::endl;
         exit(EXIT_FAILURE);
     }

     buttonText.setFont(font);
     buttonText.setString(text);
     buttonText.setCharacterSize(fontSize);
     buttonText.setFillColor(color);
     buttonText.setPosition(x, y);

     this->win->draw(buttonText);
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

 void SFML::setAreaSize(int h, int w) {
     this->height = h;
     this->width = w;
 }
