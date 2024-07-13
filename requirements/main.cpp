#include "includes/Utils.hpp"

int main(int ac, char **av) {
    Instance instance;
    ifNullLibraryDelete(instance);
    
    try {
        check_args_validity(ac, av);
        instance.setAreaSize(atoi(av[1]), atoi(av[2]));
        libraryLoop(instance);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    if (instance.getAudio())
        delete instance.getAudio();
    if (instance[SFMLCODE])
        delete instance[SFMLCODE];
    if (instance[SDLCODE]) 
        delete instance[SDLCODE];
    if (instance[GLCODE])
        delete instance[GLCODE];

    return EXIT_SUCCESS;
}