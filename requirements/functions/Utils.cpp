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
    switch(library->getKeyCode()) {
        case QUIT:
            library->closeWindow();
            library->setRunning();
            break;

        case 0:
            library->closeWindow();
            library->setRunning();
            instance->setActualLib(0);
            break;

        case 1:
            library->closeWindow();
            library->setRunning();
            instance->setActualLib(1);
            break;

        case 2:
            library->closeWindow();
            library->setRunning();
            instance->setActualLib(2);
            break;

        default:
            break;
    }
}


void libraryLoop(int w, int h, Instance instance) {
    instance.setAreaSize(w, h);
    instance[AUDIOCODE]->playSong(POKEROADSONG);
    instance[instance.getActualLib()]->display();

    while (instance[instance.getActualLib()]->getKeyCode() != QUIT)
    {
        // instance[instance.getActualLib()]->update();
        input(&instance, instance[instance.getActualLib()]);
        instance[instance.getActualLib()]->display();
    }
}