#pragma once

#include <iostream>

#include <dlfcn.h>

#include "SDL.hpp"

#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

#define SDL_PATH "./requirements/libs/libSDL.so"

void check_args_validity(int ac, char **av);
bool isNumeric(const std::string &str);

SDL* loadSDLInstance();