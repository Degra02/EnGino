cmake_minimum_required(VERSION 3.23)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio system window)

add_executable(PhysicsEngine src/main.cpp src/World.cpp include/World.h
        src/Objects/Object.cpp include/Object.h src/Utils/vector2.cpp include/vector2.h
        src/Colliders/Collisions.cpp include/Collisions.h src/Objects/Circle.cpp include/Circle.h
        src/Utils/VerletSolver.cpp include/VerletSolver.h src/Objects/ObjectSpawner.cpp include/ObjectSpawner.h src/Objects/Rectangle.cpp include/Rectangle.h src/Render.cpp include/Render.h)

target_link_libraries(PhysicsEngine -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio)