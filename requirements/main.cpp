#include "includes/Utils.hpp"

int main(int ac, char **av) {
    
    try {
        check_args_validity(ac, av);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    SDL* sdlInstance = loadSDLInstance();

    if (!sdlInstance) {
        std::cerr << "Error: Could not load SDL instance" << std::endl;
        return EXIT_FAILURE;
    }

    sdlInstance->display();

    return EXIT_SUCCESS;
}