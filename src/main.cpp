#include <iostream>
#include <cmath>
#include "../include/World.h"
#include "../include/VerletSolver.h"

//Graphics
#include <SFML/Graphics.hpp>

#define WIDTH 1500
#define HEIGHT 1000
#define FPS_LIMIT 60
#define SUBSTEPS 10

int main() {
    srand(time(nullptr));
    pheng::World world = pheng::World();
    world.setGravity({0, 981});

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Physics Engine");
    world.setConstraints(WIDTH, HEIGHT);

    window.setFramerateLimit(FPS_LIMIT);
    float dt = 1.f/FPS_LIMIT;

    pheng::VerletSolver solver(&world);

    sf::CircleShape constraint(400.f);
    constraint.setOrigin({constraint.getRadius(),constraint.getRadius()});
    constraint.setPosition({WIDTH/2,HEIGHT/2});
    constraint.setOutlineColor(sf::Color::White);
    constraint.setOutlineThickness(4);
    constraint.setFillColor(sf::Color::Black);


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

        window.draw(constraint);

        float dt_sub = dt / SUBSTEPS;
        for(int i(0); i < SUBSTEPS; ++i) {
            //Verlet's integration method
            solver.update(dt_sub); // --> Doesn't take into account the masses of the various objects


            //Normal method
            //world.step(dt_sub); // --> Calculates the correct response to the collisions
        }

        //Drawing & displaying
        for (auto &obj: world.worldObjects){
            window.draw(obj->getDrawable());
        }
        window.display();

    }

}
