#include "../include/Render.h"

namespace pheng {

    Render::Render(std::string directoryPath, float w, float h) {
        texture.create(w, h);
        this->directoryPath = directoryPath;
    }

    void Render::renderFrame(sf::RenderWindow &window) {
        texture.update(window);
        char s[14];
        sprintf(s, "img_%05d.bmp", renderNumber);
        renderNumber++;

        texture.copyToImage().saveToFile(directoryPath + s);
    }

} // pheng