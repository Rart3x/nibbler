#pragma once

#include <dlfcn.h>
#include <unistd.h>

#include "SDL.hpp"

#define SDL_PATH "./requirements/libs/libSDL.so"

SDL* loadSDLInstance();