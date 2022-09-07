#include <iostream>
#include <cmath>
#include "../include/World.h"

//Graphics
#include <SFML/Graphics.hpp>

#define WIDTH 1500
#define HEIGHT 1000
#define FPS_LIMIT 60


int main() {
    srand(time(nullptr));
    pheng::World world = pheng::World();
    world.setGravity({0, -981});

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Physics Engine");
    world.setConstraints(WIDTH, HEIGHT);

    window.setFramerateLimit(FPS_LIMIT);
    float dt = 1.f/60.f;

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

        //Verlet's integration method
        //world.update(dt);

        //Normal method
        world.step(dt);
        world.detectCollisions();

        //Drawing & displaying
        for (auto &obj: world.worldObjects){
            window.draw(obj->getDrawable());
        }
        window.display();

    }

}
