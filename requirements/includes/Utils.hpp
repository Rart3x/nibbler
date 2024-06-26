#pragma once

#include <iostream>
#include <stdexcept>

#include "../libs/openGL/openGL.hpp"



bool isNumeric(const std::string &str);

void check_args_validity(int ac, char **av);