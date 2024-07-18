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
    this->win = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!errorQuitLibWithObj(this->win, "Error: Could not create SDL window", this))
        return;
    this->renderer = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!errorQuitLibWithObj(this->renderer, "Error: Could not create SDL renderer", this))
        return;
    this->font = TTF_OpenFont(ARIAL, 24);
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
        this->win = original.win;
        this->renderer = original.renderer;
        this->font = original.font;
    }
    return *this;
}

SDL::~SDL() {
    if (this->font)
        TTF_CloseFont(this->font);
    if (this->renderer)
        SDL_DestroyRenderer(this->renderer);
    if (this->win)
        SDL_DestroyWindow(this->win);
    if (TTF_WasInit())
        TTF_Quit();
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_Quit();

}


void SDL::display() {
    SDL_RenderClear(this->renderer);

    if (this->mode == PAUSE)
        this->displayPause();
    // else
    //     this->displayGame();

    SDL_RenderPresent(this->renderer);
}

void SDL::displayPause() {
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    SDL_Color color = {255, 255, 255, 255};

    surface = TTF_RenderText_Solid(this->font, "Pause", color);
    texture = SDL_CreateTextureFromSurface(this->renderer, surface);
    rect.x = WIDTH / 2 - 50;
    rect.y = HEIGHT / 2 - 50;
    rect.w = 100;
    rect.h = 100;
    SDL_RenderCopy(this->renderer, texture, NULL, &rect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void SDL::input() {
    SDL_Event event;

    static bool pause = false;

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
                        if (!pause)
                            this->keyCode = PAUSE;
                        else
                            this->keyCode = GAME;
                        pause = !pause;                        
                        break;

                    case SDL_SCANCODE_1:
                        this->keyCode = SFMLCODE;
                        break;

                    case SDL_SCANCODE_3:
                        this->keyCode = SDLCODE;
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

void SDL::pause() {
    if (this->mode == PAUSE)
        this->mode = GAME;
    else
        this->mode = PAUSE;
}

void SDL::update() {
    this->input();
    this->display();
}