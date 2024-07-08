#include "../includes/Utils.hpp"

bool isNumeric(const std::string& str) {
    for (char c : str)
        if (!isdigit(c))
            return false;
    return true;
}


void check_args_validity(int ac, char **av) {

    if (ac != 3)
        throw std::runtime_error("Error: invalid number of arguments");

    std::string width = av[1];
    std::string height = av[2];

    if (!isNumeric(width) || !isNumeric(height))
        throw std::runtime_error("Error: numeric arguments required");
}


void libraryLoop(int w, int h, Instance instance) {
    instance.setAreaSize(w, h);
    instance[SFMLCODE]->display();

    while (instance[instance.getActualLib()]->getLibCode() != 404)
    {
        switch (instance[instance.getActualLib()]->getLibCode())
        {
            case GLCODE:
                instance[instance.getActualLib()]->closeWindow();
                instance.setActualLib(GLCODE);
                instance[GLCODE]->display();
                break;
            case SDLCODE:
                instance[instance.getActualLib()]->closeWindow();
                instance.setActualLib(SDLCODE);
                instance[SDLCODE]->display();
                break;
            case SFMLCODE:
                instance[instance.getActualLib()]->closeWindow();
                instance.setActualLib(SFMLCODE);
                instance[SFMLCODE]->display();
                break;
            default:
                break;
        }
    }
}