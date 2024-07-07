#include "../includes/SDL.hpp"

extern "C" {
    SDL *createSDLInstance() {
        return new SDL();
    }
}


SDL::SDL(void) : Library() {
    
    if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)) {
        std::cerr << "Error: Could not initialize SDL" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->running = false;
    this->libCode = 0;
    this->selectedButton = 0;
    this->winH = HEIGHT;
    this->winW = WIDTH;
}


SDL::~SDL() {
    if (this->win)
        SDL_DestroyWindow(this->win);
    if (this->renderer)
        SDL_DestroyRenderer(this->renderer);
}


void SDL::closeWindow() {
    if (this->win) {
        SDL_DestroyWindow(this->win);
        this->win = NULL;
    }
}


void SDL::display() {

    this->win = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!this->win) {
        std::cerr << "Error: Could not create SDL window" << std::endl;
        exit(EXIT_FAILURE);
    }

    TTF_Init();

    this->renderer = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->running = true;

    while (this->running) {
        this->input();
        this->displayMenu();
        SDL_Delay(16);
    }
}


void SDL::displayMenu() {
    SDL_Color black = {BLACK};
    SDL_Rect startButton, quitButton;

    startButton.w = quitButton.w = 200;
    startButton.h = quitButton.h = 50;

    int totalButtonHeight = startButton.h + quitButton.h;

    startButton.y = (this->winH - totalButtonHeight) / 2;
    quitButton.y = startButton.y + startButton.h + 10;
    
    startButton.x = (this->winW - startButton.w) / 2;
    quitButton.x = startButton.x;

    if (this->selectedButton == 0)
        SDL_SetRenderDrawColor(this->renderer, CYAN);
    else
        SDL_SetRenderDrawColor(this->renderer, WHITE);

    SDL_RenderFillRect(this->renderer, &startButton);

    if (this->selectedButton == 1)
        SDL_SetRenderDrawColor(this->renderer, CYAN);
    else
        SDL_SetRenderDrawColor(this->renderer, WHITE);
    
    SDL_RenderFillRect(this->renderer, &quitButton);

    this->drawTitle();
    this->drawText("Start", startButton, black);
    this->drawText("Quit", quitButton, black);

    SDL_RenderPresent(this->renderer);
}


void SDL::drawText(const std::string& text, const SDL_Rect& pos, const SDL_Color& color) {

    TTF_Font* font = TTF_OpenFont(ARIAL, 24);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);

    SDL_FreeSurface(surface);

    SDL_Rect dstrect = pos;
    SDL_RenderCopy(this->renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}


void SDL::drawTitle() {

    TTF_Font* font = TTF_OpenFont(SCIENCE, 48);
    SDL_Surface* surface = TTF_RenderText_Solid(font, "Nibbler", {255, 255, 255, 255});
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);

    SDL_FreeSurface(surface);

    int textWidth, textHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);

    int titleX = (this->winW - textWidth) / 2;
    int titleY = 20;

    SDL_Rect dstrect = {titleX, titleY, textWidth, textHeight};
    SDL_RenderCopy(this->renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}


void SDL::input() {
    SDL_Event event;
 
    while (SDL_PollEvent(&event)) {
        switch (event.type) {

        case SDL_QUIT:
            this->running = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {

            case SDL_SCANCODE_ESCAPE:
                this->libCode = 404;
                this->running = false;
                break;

            case SDL_SCANCODE_RETURN:
                if (this->selectedButton == 0)
                    break;
                else {
                    this->libCode = 404;
                    this->running = false;
                }
                break;

            case SDL_SCANCODE_1:
                this->libCode = 0;
                this->running = false;
                break;

            case SDL_SCANCODE_3:
                this->libCode = 2;
                this->running = false;
                break;

            case SDL_SCANCODE_W:
                break;

            case SDL_SCANCODE_A:
                break;

            case SDL_SCANCODE_S:
                break;

            case SDL_SCANCODE_D:
                break;

            case SDL_SCANCODE_UP:
                if (this->selectedButton == 1)
                    this->selectedButton = 0;
                break;
            case SDL_SCANCODE_DOWN:
                if (this->selectedButton == 0)
                    this->selectedButton = 1;
                break;
            case SDL_SCANCODE_LEFT:
                break;
            case SDL_SCANCODE_RIGHT:
                break;

            default:
                break;
            }
        }
    }
}

size_t SDL::getLibCode() const {
    return this->libCode;
}

void SDL::setAreaSize(int h, int w) {
    this->height = h;
    this->width = w;
}

void SDL::setWinSize(int h, int w) {
    this->winH = h;
    this->winW = w;
}