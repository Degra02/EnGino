#include <iostream>
#include "../include/World.h"
#include "../include/Circle.h"
#include "../include/Collisions.h"

//Graphics
#include <SFML/Graphics.hpp>

int main() {
    phy_eng::World world = phy_eng::World(0.01);

    phy_eng::Circle s(5, {0, 0});

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Physics Engine");

    phy_eng::Circle circle = phy_eng::Circle(50, {50, 100});
    circle.setMass(10);
    world.addObject(circle);

    while (window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();

                case sf::Event::KeyPressed: {

                }
            }
        }
        window.clear();

        world.step();

        window.draw(circle.getCircleShape());
        window.display();
    }

}
