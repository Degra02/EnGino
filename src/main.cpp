#include <iostream>
#include <cmath>
#include "../include/World.h"
#include "../include/VerletSolver.h"

//Graphics
#include <SFML/Graphics.hpp>

#define WIDTH 1500
#define HEIGHT 1000
#define FPS_LIMIT 30
#define SUBSTEPS 10 //Accuracy of the simulation

int main() {
    srand(time(nullptr));

    sf::Font font;
    font.loadFromFile("font.TTF");

    pheng::World world = pheng::World(font);
    world.setGravity({0, 981});

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "EnGino");
    world.setConstraints(WIDTH, HEIGHT);

    window.setFramerateLimit(FPS_LIMIT);
    float dt = 1.f/FPS_LIMIT;
    float dt_sub = dt / SUBSTEPS;

    // Percentage of velocity kept after each collision
    float restitution_coef = 1;

    pheng::VerletSolver solver(&world);

    world.addSpawner(new pheng::ObjectSpawner({WIDTH/2.f , HEIGHT/3.f}, 1));
    //world.addSpawner(new pheng::ObjectSpawner({WIDTH/3.f, HEIGHT/3.f}, 5));

    /**sf::Texture texture;
    std::string filename = "/home/degra/Coding/C++/EnGino/Renders/";
    texture.create(WIDTH, HEIGHT);**/

    int number = 0;
    while (window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();

                case sf::Event::KeyPressed: {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                        world.setPaused();
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
                        world.removeAll();
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        world.toggleSpawners();
                    }
                }

                case sf::Event::MouseButtonPressed: {
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                       world.spawnCircle(event.mouseButton.x, event.mouseButton.y);
                    }
                }
            }
        }
        window.clear();

        world.spawnObjectsSpawner();

        for(int i(0); i < SUBSTEPS; ++i) {
            //Verlet's integration method
            //solver.update(dt_sub); // --> Doesn't take into account the masses of the various objects

            //Normal method
            world.step(dt_sub, restitution_coef); // --> Calculates the correct response to the collisions
        }

        world.drawObjects(&window);

        window.display();

        /**
        texture.update(window);
        char s[12];
        sprintf(s, "img_%03d.png", number);
        texture.copyToImage().saveToFile(filename + s);
        number++;**/
    }

}
