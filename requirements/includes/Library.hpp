#pragma once

class Library {

    public:
        Library();
        virtual ~Library();

        virtual void display() = 0;
        virtual void input() = 0;

        virtual unsigned int getLibCode() const = 0;
    
    private:
        bool running;
        unsigned int libCode;
};