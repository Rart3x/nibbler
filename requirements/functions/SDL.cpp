#include "../includes/SDL.hpp"

extern "C" {
    SDL *createSDLInstance() {
        return new SDL();
    }
}


SDL::SDL(void) : Library() {
    
    if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1))
    {
        std::cerr << "Error: Could not initialize SDL" << std::endl;
        exit(EXIT_FAILURE);
    }

    TTF_Init();

    this->mode = PAUSE;
    this->running = false;
    this->winH = HEIGHT;
    this->winW = WIDTH;
}


SDL::~SDL() {
    if (TTF_WasInit())
        TTF_Quit();
}


void SDL::closeWindow() {
    if (this->win)
    {
        SDL_DestroyWindow(this->win);
        this->win = NULL;
    }
}


void SDL::display() {

    this->win = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!this->win)
    {
        std::cerr << "Error: Could not create SDL window" << std::endl;
        this->libCode = 404;
        return;
    }

    this->renderer = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->running = true;

    while (this->running)
    {
        this->input();

        if (this->mode == GAME)
        {
            SDL_RenderClear(this->renderer);
            this->drawTitle();
        }
        else if (this->mode == PAUSE)
        {
            SDL_RenderClear(this->renderer);
            this->drawTitle();
            this->displayPause();
        }

        SDL_RenderPresent(this->renderer);
        SDL_Delay(16);
    }
}


void SDL::displayPause() {
    TTF_Font* font = TTF_OpenFont(ARIAL, 72);
    SDL_Surface* surface = TTF_RenderText_Solid(font, "Pause", {WHITE});
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);

    int textWidth, textHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);

    int centerX = this->winW / 2;
    int centerY = this->winH / 2;
    int titleX = centerX - textWidth / 2;
    int titleY = centerY - textHeight / 2;

    SDL_Rect dstrect = {titleX, titleY, textWidth, textHeight};
    
    SDL_RenderCopy(this->renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}


void SDL::drawTitle() {
    TTF_Font* font = TTF_OpenFont(SCIENCE, 48);
    SDL_Surface* surface = TTF_RenderText_Solid(font, "Nibbler", {WHITE});
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);

    int textWidth, textHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);

    int titleX = (this->winW - textWidth) / 2;
    int titleY = 20;

    SDL_Rect dstrect = {titleX, titleY, textWidth, textHeight};
    
    SDL_RenderCopy(this->renderer, texture, NULL, &dstrect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
}


void SDL::input() {
    SDL_Event event;
 
    while (SDL_PollEvent(&event)) 
    {
        switch (event.type)
        {
            case SDL_QUIT:
                this->running = false;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) 
                {
                    case SDL_SCANCODE_ESCAPE:
                        this->libCode = 404;
                        this->running = false;
                        break;

                    case SDL_SCANCODE_RETURN:
                        break;
                    
                    case SDL_SCANCODE_SPACE:
                        if (this->mode == PAUSE)
                            this->mode = GAME;
                        else if (this->mode == GAME)
                            this->mode = PAUSE;
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
                        break;
                    case SDL_SCANCODE_DOWN:
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

void SDL::setLibCode(int code) {
    this->libCode = code;
}

void SDL::setRunning() {
    this->running = true;
}

void SDL::setWinSize(int h, int w) {
    this->winH = h;
    this->winW = w;
}