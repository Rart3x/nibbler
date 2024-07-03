#include "includes/Utils.hpp"

int main(int ac, char **av) {

    SDL* instance = loadSDLInstance();

    if (!instance) {
        std::cerr << RED << "Error: Could not load SDL instance" << RESET << std::endl;
        return EXIT_FAILURE;
    }

    try {
        check_args_validity(ac, av);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    instance->display();

    return EXIT_SUCCESS;
}