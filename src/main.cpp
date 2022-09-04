#include <iostream>
#include "../include/World.h"
#include "../include/Circle.h"
#include "../include/Collisions.h"

//Graphics
#include <SFML/Graphics.hpp>

#define WIDTH 1000
#define HEIGHT 1000

int main() {
    phy_eng::World world = phy_eng::World(0.01);
    world.setGravity({0, -0.1});

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Physics Engine");
    world.setConstraints(window.getSize().x, window.getSize().y);

    phy_eng::Circle circle = phy_eng::Circle(10, {90, 100}, 10);
    phy_eng::Circle circle2 = phy_eng::Circle(50, {200, 200}, 10);
    circle2.setMobility(phy_eng::Mobility::FIXED);

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
