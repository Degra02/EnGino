#include <iostream>
#include <cmath>
#include "../include/World.h"
#include "../include/Circle.h"

//Graphics
#include <SFML/Graphics.hpp>

#define WIDTH 1500
#define HEIGHT 1000

void spawnCircle(pheng::World *world);

int main() {
    pheng::World world = pheng::World(0.01);

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Physics Engine");
    world.setConstraints(WIDTH, HEIGHT);

    /**
    for (int i = 0; i < 100; i++){
        pheng::Circle* c = new pheng::Circle(5, {static_cast<float>(rand() % WIDTH), -static_cast<float>(rand() % HEIGHT)}, 10);
        c->setVelocity({static_cast<float>(rand() % 25), 0});
        world.addObject(c);
    }**/

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

                case sf::Event::MouseButtonPressed: {
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        spawnCircle(&world);
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

void spawnCircle(pheng::World *world){
    auto* c = new pheng::Circle(20, {static_cast<float>(rand() % WIDTH),
                                     -static_cast<float>(rand() % HEIGHT)}, 10);
    c->setVelocity({static_cast<float>(rand() % 25), 0});
    world->addObject(c);
}
