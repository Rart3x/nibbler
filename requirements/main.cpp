#include "includes/Utils.hpp"

int main(int ac, char **av) {

    // GL * GLinstance = loadGLInstance();
    // SDL* SDLinstance = loadSDLInstance();
    SFML* SFMLinstance = loadSFMLInstance();

    // if (!GLinstance) {
    //     std::cerr << RED << "Error: Could not load GL instance" << RESET << std::endl;
    //     return EXIT_FAILURE;
    // }

    // if (!SDLinstance) {
    //     std::cerr << RED << "Error: Could not load SDL instance" << RESET << std::endl;
    //     return EXIT_FAILURE;
    // }

    if (!SFMLinstance) {
        std::cerr << RED << "Error: Could not load SFML instance" << RESET << std::endl;
        return EXIT_FAILURE;
    }

    try {
        check_args_validity(ac, av);
        // GLinstance->display();
        // SDLinstance->display();
        SFMLinstance->display();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}