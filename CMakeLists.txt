cmake_minimum_required(VERSION 3.23)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(PhysicsEngine src/main.cpp src/World.cpp include/World.h
         src/Object.cpp include/Object.h src/vector2.cpp include/vector2.h src/Colliders/Collider.cpp include/Collider.h src/Sphere.cpp include/Sphere.h src/Colliders/SphereCollider.cpp include/SphereCollider.h)
