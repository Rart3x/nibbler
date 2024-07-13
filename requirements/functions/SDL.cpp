#include "../includes/SDL.hpp"

extern "C" {
    SDL *createSDLInstance() {
        return new SDL();
    }
}


SDL::SDL(void) : Library() {
    if (!errorQuitLibWithint(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO), "Error: Could not initialize SDL", this))
        return;
    if (!errorQuitLibWithint(TTF_Init(), "Error: Could not initialize SDL TTF", this))
        return;
    this->win = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_HIDDEN);
    if (!errorQuitLibWithObj(this->win, "Error: Could not create SDL window", this))
        return;
    this->renderer = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!errorQuitLibWithObj(this->renderer, "Error: Could not create SDL renderer", this))
        return;
    this->isWindowOpen = false;
}

SDL::SDL(const SDL &original) {
    *this = original;
}

SDL& SDL::operator=(const SDL& original) {
    if (this != &original)
    {
        this->height = original.height;
        this->width = original.width;
        this->keyCode = original.keyCode;
        this->mode = original.mode;
        this->prevMode = original.prevMode;
        this->winH = original.winH;
        this->winW = original.winW;
        this->win = original.win;
        this->isWindowOpen = original.isWindowOpen;
        this->renderer = original.renderer;
        this->font = original.font;
    }
    return *this;
}

SDL::~SDL() {
    if (TTF_WasInit())
        TTF_Quit();
}


void SDL::closeWindow() {
    if (this->win)
    {
        SDL_DestroyWindow(this->win); 
        this->isWindowOpen = false;
    }
}

void SDL::openWindow() {
    if (this->win)
    {
        this->win = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->winW, this->winH, 0);
        this->isWindowOpen = true;
    }
}

void SDL::display() {
    if (this->win && !this->isWindowOpen)
        this->openWindow();

    SDL_RenderPresent(this->renderer);
    SDL_Delay(16);
}

void SDL::input() {
    SDL_Event event;
 
    while (SDL_PollEvent(&event)) 
    {
        switch (event.type)
        {
            case SDL_QUIT:
                this->keyCode = QUIT;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) 
                {
                    case SDL_SCANCODE_ESCAPE:
                        this->keyCode = QUIT;
                        break;

                    case SDL_SCANCODE_RETURN:
                        break;
                    
                    case SDL_SCANCODE_SPACE:
                        break;

                    case SDL_SCANCODE_1:
                        this->keyCode = SFMLCODE;
                        break;

                    case SDL_SCANCODE_3:
                        this->keyCode = GLCODE;
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

void SDL::update() {
    this->input();
    this->display();
}