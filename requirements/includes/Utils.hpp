#pragma once

#include <iostream>

#include <dlfcn.h>

#include "GL.hpp"
#include "SDL.hpp"
#include "SFML.hpp"

#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

#define GL_PATH "./requirements/libs/GL.so"
#define SDL_PATH "./requirements/libs/SDL.so"
#define SFML_PATH "./requirements/libs/SFML.so"

void check_args_validity(int ac, char **av);
bool isNumeric(const std::string &str);

GL*     loadGLInstance();
SDL*    loadSDLInstance();
SFML*   loadSFMLInstance();