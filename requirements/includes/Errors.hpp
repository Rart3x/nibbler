#pragma once

#include <iostream>
#include <string>

#include "Library.hpp"

class Library;

bool    error(void* obj, std::string text, void* toDelete = NULL, int (*deleteFunc)(void *) = NULL);
bool    errorQuitLibWithBool(bool boolean, std::string text, Library *lib);
bool    errorQuitLibWithint(int i, std::string text, Library *lib);
bool    errorQuitLibWithObj(void *obj, std::string text, Library *lib);

void    printError(std::string text);