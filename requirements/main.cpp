#include "includes/Utils.hpp"

std::vector<std::string> mapTest = {
    "11111111111111111111111111111",
    "10000000000000000000000000001",
    "10000000000000000000000000001",
    "10000000000000000000000000001",
    "10000000000000000000000000001",
    "10000000000000000000000000001",
    "11111111111111111111111111111"
};

std::vector<std::string> mapTest1 = {
    "11111111111111111111111111111",
    "10000000000000000000000000001",
    "100000SSSSSSSSSSSSSSS00000001",
    "11111111111111111111111111111"
    "10000000000000000000000000001",
    "10000000000000000000000000001",
    "11111111111111111111111111111"
};


int main(int ac, char **av) {
    try
    {
        check_args_validity(ac, av);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    Instance instance;

    instance.setAreaSize(atoi(av[1]), atoi(av[2]));
    instance[AUDIOCODE]->playMusic(POKEROADSONG);

    while (instance[0]->getKeyCode() != QUIT)
    {   
        instance[0]->update();

        if (instance[0]->getKeyCode() == UP)
            lowerMusicVolumeAndPlaySound(instance[AUDIOCODE], APPLESONG);
        if (instance[0]->getKeyCode() == RIGHT)
            instance[0]->setMap(mapTest1);
        else if (instance[0]->getKeyCode() == LEFT)
            instance[0]->setMap(mapTest);
        else
            instance[0]->setMap(mapTest);

        input(instance[AUDIOCODE], instance[0], &instance, instance[0]->getKeyCode(), mapTest);
    }

    if (instance[AUDIOCODE])
        delete instance[AUDIOCODE];
    if (instance[0])
        delete instance[0];

    return EXIT_SUCCESS;
}