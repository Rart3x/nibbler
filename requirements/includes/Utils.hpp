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

class Instance;

bool        isNumeric(const std::string &str);

void        check_args_validity(int ac, char **av);
void        libraryLoop(int h, int w, Instance instance);