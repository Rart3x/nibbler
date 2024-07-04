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
        while (instance->getLibCode() != 404) {
            switch (instance->getLibCode()) {
                case 1:
                    delete instance;
                    instance = loadGLInstance();
                    instance->display();
                    break;
                case 2:
                    delete instance;
                    instance = loadSDLInstance();
                    instance->display();
                    break;
                case 3:
                    delete instance;
                    instance = loadSFMLInstance();
                    instance->display();
                    break;
                default:
                    break;
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    delete instance;

    return EXIT_SUCCESS;
}