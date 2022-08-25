cmake_minimum_required(VERSION 3.23)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(PhysicsEngine src/main.cpp src/World.cpp include/World.h
        src/Objects/Object.cpp include/Object.h src/vector2.cpp include/vector2.h src/Colliders/Collisions.cpp include/Collisions.h src/Objects/Sphere.cpp include/Sphere.h)
