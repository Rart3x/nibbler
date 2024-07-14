#include "../includes/Utils.hpp"

bool isNumeric(const std::string& str) {
    for (char c : str)
        if (!isdigit(c))
            return false;
    return true;
}

void ifNullLibraryDelete(Instance instance) {
    if (!instance.getAudio())
        exit(EXIT_FAILURE);

    if (!instance[0])
    {
        delete instance.getAudio();
        exit(EXIT_FAILURE);
    }
}

void check_args_validity(int ac, char **av) {
    if (ac != 3)
        throw std::runtime_error(RED "Error: invalid number of arguments" RESET);

    std::string width = av[1];
    std::string height = av[2];

    if (!isNumeric(width) || !isNumeric(height))
        throw std::runtime_error(RED "Error: numeric arguments required" RESET);

    if (std::stoi(width) > MAX_W || std::stoi(height) > MAX_H)
        throw std::runtime_error(RED "Error: invalid area size" RESET);
}


void input(Instance *instance, int code) {
    switch(code)
    {
        case SFMLCODE:
            instance->unloadAndLoad(SFMLCODE);
            break;

        case NCCODE:
            instance->unloadAndLoad(NCCODE);
            break;

        case GLCODE:
            instance->unloadAndLoad(GLCODE);
            break;

        default:
            break;
    }
}

void libraryLoop(Instance instance) {
    // instance[AUDIOCODE]->playSong(POKEROADSONG);
    instance.getLib()->display();

    while (instance.getLib()->getKeyCode() != QUIT)
    {
        input(&instance, instance.getLib()->getKeyCode());
        instance.getLib()->update();
    }
}