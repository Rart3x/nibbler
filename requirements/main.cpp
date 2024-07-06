#include "includes/Utils.hpp"

int main(int ac, char **av) {

    Instance instance;

    try {
        check_args_validity(ac, av);
        libraryLoop(atoi(av[1]), atoi(av[2]), instance);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    delete instance[GLCODE];
    delete instance[SDLCODE];
    delete instance[SFMLCODE];

    return EXIT_SUCCESS;
}