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

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Physics Engine");
    world.setConstraints(window.getSize().x, window.getSize().y);

    pheng::Circle circle = pheng::Circle(50, {100, 100}, 10);
    pheng::Circle circle2 = pheng::Circle(50, {200, 200}, 10);
    circle2.setMobility(pheng::Mobility::FIXED);

    world.addObjects({&circle, &circle2});

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
