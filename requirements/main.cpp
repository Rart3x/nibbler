#include "includes/Utils.hpp"

std::vector<std::string> mapTest = {
    "111111",
    "100001",
    "100001",
    "100001",
    "100001",
    "111111"
};

std::vector<std::string> mapTest1 = {
    "111111",
    "111111",
    "111111",
    "111111",
    "111111",
    "111111"
};


int main(int ac, char **av) {
    Instance instance;
    
    try
    {
        check_args_validity(ac, av);
        instance.setAreaSize(atoi(av[1]), atoi(av[2]));
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    instance[AUDIOCODE]->playSong(POKEROADSONG);

    while (instance[0]->getKeyCode() != QUIT)
    {   
        if (instance[0]->getKeyCode() == RIGHT)
            instance[0]->setMap(mapTest1);
        else if (instance[0]->getKeyCode() == LEFT)
            instance[0]->setMap(mapTest);
        else
            instance[0]->setMap(mapTest);

        input(instance[AUDIOCODE], instance[0], &instance, instance[0]->getKeyCode());
        instance[0]->update();
    }

    if (instance[AUDIOCODE])
        delete instance[AUDIOCODE];
    if (instance[0])
        delete instance[0];

    return EXIT_SUCCESS;
}