#pragma once

class Library {

    public:
        Library();
        virtual ~Library();

        virtual void display() = 0;
        virtual void input() = 0;
};