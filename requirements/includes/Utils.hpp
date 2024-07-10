#pragma once

#include <algorithm>
#include <iostream>

#include <dlfcn.h>

#include "Instance.hpp"

#include "GL.hpp"
#include "SDL.hpp"
#include "SFML.hpp"

class Instance;

bool        isNumeric(const std::string &str);

void        check_args_validity(int ac, char **av);
void        ifNullLibraryDelete(Instance instance);
void        libraryLoop(int h, int w, Instance instance);