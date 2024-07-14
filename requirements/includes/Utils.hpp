#pragma once

#include <algorithm>
#include <iostream>

#include <dlfcn.h>

#include "Instance.hpp"

#include "Audio.hpp"
#include "GL.hpp"
#include "NC.hpp"
#include "SFML.hpp"

class Instance;

bool        isNumeric(const std::string &str);

void        check_args_validity(int ac, char **av);
void        ifNullLibraryDelete(Instance instance);
void        input(Audio* audio, Library* lib, Instance *instance, int code);