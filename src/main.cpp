#include <iostream>
#include "../include/World.h"
#include "../include/Circle.h"
#include "../include/Collisions.h"

//Graphics
#include <SFML/Graphics.hpp>

#define WIDTH 1000
#define HEIGHT 1000

int main() {
    pheng::World world = pheng::World(0.01);
    world.setGravity({0, -2});

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Physics Engine");
    world.setConstraints(WIDTH, HEIGHT);

    pheng::Circle circle = pheng::Circle(25, {200, 200}, 10);
    circle.setVelocity({10, 5});

    world.addObjects({&circle});

    while (window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();

                case sf::Event::KeyPressed: {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                        world.setPaused();
                    }
                }
            }
        }
        window.clear();

        world.step();
        for (auto &obj: world.worldObjects){
            window.draw(obj->getDrawable());
        }

        window.display();
    }

}
