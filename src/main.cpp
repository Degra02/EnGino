#include <iostream>
#include <cmath>

#include "../include/World.h"
#include "../include/VerletSolver.h"
#include "../include/Render.h"

//Graphics
#include <SFML/Graphics.hpp>

#define WIDTH 1500
#define HEIGHT 1000
#define FPS_LIMIT 60
#define SUBSTEPS 10 //Accuracy of the simulation


int main() {
    srand(time(nullptr));

    sf::Font font;
    font.loadFromFile("font.TTF");

    pheng::World world = pheng::World(font);
    world.setGravity({0, 981});

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "EnGino");
    world.setConstraints(WIDTH, HEIGHT);
    sf::RectangleShape border({WIDTH, HEIGHT});
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::White);
    border.setOutlineThickness(4);

    window.setFramerateLimit(FPS_LIMIT);
    float dt = 1.f/FPS_LIMIT;
    float dt_sub = dt / SUBSTEPS;

    // Percentage of velocity kept after each collision
    float restitution_coef = 1;

    // For Verlet calculus
    // pheng::VerletSolver solver(&world);

    //Object spawners
    int radius[2] = {10, 20};
    world.addSpawner(new pheng::ObjectSpawner({WIDTH/1.5 , HEIGHT/3.f}, 2, radius));
    world.addSpawner(new pheng::ObjectSpawner({WIDTH/3.f , HEIGHT/3.f}, 2, radius));

    //Focus camera
    sf::View camera({WIDTH/2.f, HEIGHT/2.f}, {WIDTH, HEIGHT});
    pheng::Object *focusedObject = nullptr;
    bool isFocused = false;


    //Renderer initialization
    std::string directoryPath = "/home/degra/Coding/C++/EnGino/Renders/";
    pheng::Render rendered(directoryPath, WIDTH, HEIGHT);

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
                        camera.setCenter(WIDTH/2.f, HEIGHT/2.f);
                    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        world.toggleSpawners();
                    }
                }

                case sf::Event::MouseButtonPressed: {
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                       world.spawnCircle(event.mouseButton.x, event.mouseButton.y);
                    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                        if (!isFocused) {
                            for (auto &obj: world.getWorldObjects()) {
                                if (pheng::vector2::norm({static_cast<float >(event.mouseButton.x),
                                                          static_cast<float >(event.mouseButton.y)},
                                                         obj->getCenter()) < obj->getSize()) {
                                    focusedObject = obj;
                                    camera.zoom(0.5);
                                    isFocused = true;
                                }
                            }
                        } else {
                            camera.setCenter(WIDTH / 2.f, HEIGHT / 2.f);
                            camera.zoom(2);
                            isFocused = false;
                        }
                    }
                }
            }
        }
        window.clear();

        if (isFocused) {
            camera.setCenter(focusedObject->getCenter().getX(), focusedObject->getCenter().getY());
            sf::RectangleShape direction({static_cast<float>(focusedObject->Velocity.norm()/7), 3});
            direction.setPosition(focusedObject->Position.getX(), focusedObject->Position.getY());
            direction.setRotation(static_cast<float>(focusedObject->Velocity.angle() * (180.f / M_PI)));
            window.draw(direction);
            world.updateObjLegend(focusedObject, {camera.getCenter().x, camera.getCenter().y});
        }
        window.setView(camera);

        window.draw(border);
        world.spawnObjectsSpawner();

        for(uint8_t i(0); i < SUBSTEPS; ++i) {
            //Verlet's integration method
            //solver.update(dt_sub); // --> Doesn't take into account the masses of the various objects

            //Normal method
            world.step(dt_sub, restitution_coef); // --> Calculates the correct response to the collisions
        }

        world.drawObjects(&window);

        window.display();

        //rendered.renderFrame(window);
    }

}
