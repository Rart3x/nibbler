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

    this->win = NULL;
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
        this->running = original.running;
        this->winH = original.winH;
        this->winW = original.winW;
        this->win = original.win;
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
        this->win = NULL;
    }
}


void SDL::display() {
    if (this->win)
        this->closeWindow();
    this->win = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!errorQuitLibWithObj(this->win, "Error: Could not create SDL window", this))
        return;

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
    int textWidth, textHeight;

    TTF_Font* font = TTF_OpenFont(ARIAL, 72);
    if (!errorQuitLibWithObj(font, "Error: Could not load font", this))
        return;
    SDL_Surface* surface = TTF_RenderText_Solid(font, "Pause", {WHITE});
    if (!errorQuitLibWithObj(surface, "Error: Could not create surface", this))
        return;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);
    if (!errorQuitLibWithObj(texture, "Error: Could not create texture", this))
        return;

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
    int textWidth, textHeight;

    TTF_Font* font = TTF_OpenFont(SCIENCE, 48);
    if (!errorQuitLibWithObj(font, "Error: Could not load font", this))
        return;
    SDL_Surface* surface = TTF_RenderText_Solid(font, "Nibbler", {WHITE});
    if (!errorQuitLibWithObj(surface, "Error: Could not create surface", this))
        return;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(this->renderer, surface);
    if (!errorQuitLibWithObj(texture, "Error: Could not create texture", this))
        return;

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
                        this->keyCode = QUIT;
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
                        this->keyCode = 0;
                        this->running = false;
                        break;

                    case SDL_SCANCODE_3:
                        this->keyCode = 2;
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

void SDL::update() {
    return;
}