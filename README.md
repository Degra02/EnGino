# EnGino
Personal Physics Engine.

Currently there are two different implementations of position calculus.  
It still is a WIP, and will be for a long time.

## Normal method
Movement is calculated with normal time law of motion.  
Collision response utilizes the correct equations, meaning that it simulates as good as possible the correct directions and modules of velocity of the objects colliding.  
Currently utilizes a restitution coefficient that simulates energy loss during collisions.  


## Verlet's integration
Using [Verlet's integration](https://en.wikipedia.org/wiki/Verlet_integration), the object's position and collision response is approximated, meaning that it's not "accurate" in terms of physics simulation but faster computational times.  


## TODO
-- Calculate correct energy loss at collision.  
-- Implement [Sweep and Prune](https://en.wikipedia.org/wiki/Sweep_and_prune) algorithm for object collision detection.  
-- Add different object types and the respective object collision.  
-- Implement total energy level.  
-- Implement rotational objects and fixed objects.  
