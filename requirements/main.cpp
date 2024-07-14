#include "includes/Utils.hpp"

int main(int ac, char **av) {
    Instance instance;
    ifNullLibraryDelete(instance);
    
    try {
        check_args_validity(ac, av);
        instance.setAreaSize(atoi(av[1]), atoi(av[2]));
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // instance[AUDIOCODE]->playSong(POKEROADSONG);

    while (instance[0]->getKeyCode() != QUIT)
    {
        input(&instance, instance[0]->getKeyCode());
        instance[0]->update();
    }

    if (instance[AUDIOCODE])
        delete instance[AUDIOCODE];
    if (instance[0])
        delete instance[0];

    return EXIT_SUCCESS;
}