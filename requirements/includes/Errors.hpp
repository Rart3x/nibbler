#pragma once

#include <iostream>
#include <string>

#include "Library.hpp"

#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

class Library;

bool    error(void* obj, std::string text);
bool    errorQuitLib(void *obj, std::string text, Library *lib);

void    printError(std::string text);