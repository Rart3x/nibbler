#include "includes/Utils.hpp"

int main(int ac, char **av) {
    
    try {
        check_args_validity(ac, av);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    SDL sdl;

    sdl.display();
}