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


void input(Audio* audio, Library *lib, Instance *instance, int code) {
    (void)lib;
    switch(code)
    {
        case SFMLCODE:
            instance->unloadAndLoad(SFMLCODE);
            audio->playSong(POKEROADSONG);
            break;

        case NCCODE:
            instance->unloadAndLoad(NCCODE);
            audio->playSong(POKEROADSONG);
            break;

        case GLCODE:
            instance->unloadAndLoad(GLCODE);
            audio->playSong(POKEROADSONG);
            break;

        case UP:
        case DOWN:
        case LEFT:
        case RIGHT:
            // lib->setKeyCode(NONE);
            break;

        default:
            break;
    }
}