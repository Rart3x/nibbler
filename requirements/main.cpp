#include "includes/Utils.hpp"

int main(int ac, char **av) {

    Library* instance = loadRandomInstance();

    if (!instance) {
        std::cerr << RED << "Error: Could not load library instance" << RESET << std::endl;
        return EXIT_FAILURE;
    }

    try {
        check_args_validity(ac, av);
        instance->display();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    delete instance;

    return EXIT_SUCCESS;
}