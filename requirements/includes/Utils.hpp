#pragma once

#include <algorithm>
#include <iostream>

#include <dlfcn.h>

#include "Instance.hpp"

#include "GL.hpp"
#include "SDL.hpp"
#include "SFML.hpp"

#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

#define GL_PATH "./requirements/libs/GL.so"
#define SDL_PATH "./requirements/libs/SDL.so"
#define SFML_PATH "./requirements/libs/SFML.so"

#define GLCODE      0
#define SDLCODE     1
#define SFMLCODE    2

class Instance;

bool        isNumeric(const std::string &str);

void        check_args_validity(int ac, char **av);
void        libraryLoop(int h, int w, Instance instance);