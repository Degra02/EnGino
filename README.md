# Physics Engine

Currently there are two different implementations of position calculus.  
It still is a WIP, and will be for a long time.

## Normal method
Movement is calculated with normal time law of motion.  
Collision response utilizes the correct equations, meaning that it simulates as good as possible the correct directions and modules of velocity of the objects colliding.  
This implementation, currently, is still buggy, as the circles tend to slide one to another instead of "bouncing".  
Also conservation of energy makes it so the movement goes on forever until something breaks.  

## Verlet's integration
Using [Verlet's integration](https://en.wikipedia.org/wiki/Verlet_integration), the object's position and collision resposne is approximated, meaning that it's really cool to see but not "accurate" in terms of "physics simulation".
 
