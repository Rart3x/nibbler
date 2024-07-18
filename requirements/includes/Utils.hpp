#pragma once

#include <algorithm>
#include <iostream>

#include <dlfcn.h>

#include "Instance.hpp"

#include "Audio.hpp"
#include "SDL.hpp"
#include "NC.hpp"
#include "SFML.hpp"

class Instance;

bool        isNumeric(const std::string &str);

void        check_args_validity(int ac, char **av);
void        ifNullLibraryDelete(Instance instance);
void        input(Audio* audio, Library* lib, Instance *instance, int code, std::vector<std::string> map = {});
void        lowerMusicVolumeAndPlaySound(Audio* audio, const std::string& sound);

int         windowHeight(const std::vector<std::string> &map);
int         windowWidth(const std::vector<std::string> &map);