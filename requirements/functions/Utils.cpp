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

    if (!instance[SFMLCODE])
    {
        delete instance.getAudio();
        exit(EXIT_FAILURE);
    }
    
    if (!instance[SDLCODE])
    {
        delete instance.getAudio();
        delete instance[SFMLCODE];
        exit(EXIT_FAILURE);
    }
    
    if (!instance[GLCODE])
    {
        delete instance.getAudio();
        delete instance[SFMLCODE];
        delete instance[SDLCODE];
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


void input(Instance *instance, Library* library) {
    switch(library->getKeyCode())
    {
        case SFMLCODE:
            instance->setActualLib(SFMLCODE);
            library->closeWindow();
            break;

        case SDLCODE:
            instance->setActualLib(SDLCODE);
            library->closeWindow();
            break;

        case GLCODE:
            instance->setActualLib(GLCODE);
            library->closeWindow();
            break;

        default:
            break;
    }
    library->setKeyCode(NONE);
}

void libraryLoop(Instance instance) {
    // instance[AUDIOCODE]->playSong(POKEROADSONG);
    instance[instance.getActualLib()]->display();

    while (instance[instance.getActualLib()]->getKeyCode() != QUIT)
    {
        input(&instance, instance[instance.getActualLib()]);
        instance[instance.getActualLib()]->update();
    }
}