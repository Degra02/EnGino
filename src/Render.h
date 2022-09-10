#ifndef PHYSICSENGINE_RENDER_H
#define PHYSICSENGINE_RENDER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace pheng {

    class Render { // max number of frames = 10k (changeable in renderFrame function)
    private:
        int renderNumber = 0;
        sf::Texture texture;
        std::string directoryPath;

    public:
        Render(std::string directoryPath, double w, double h);

        void renderFrame(sf::RenderWindow &window);
    };

} // pheng

#endif //PHYSICSENGINE_RENDER_H
