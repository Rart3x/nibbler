#pragma once 

#include <iostream>

#include "Library.hpp"
#include "Utils.hpp"

class Utils;

class Instance {
    public:
        Instance();
        ~Instance();

        size_t getActualLib() const;

        void setActualLib(size_t i);

        Library* operator[](size_t i);
    private:
        size_t actualLib;

        Library* libs[3];
};