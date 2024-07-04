#include "includes/Utils.hpp"

int main(int ac, char **av) {

    Instance instance;

    try {
        check_args_validity(ac, av);
        libraryLoop(instance);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}