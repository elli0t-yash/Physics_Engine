## Particle Simulation

This code represents a simple particle simulation that models the movement and interaction of particles in a 3D space. The simulation applies basic physics principles, such as gravitational force and collision response, to update the state of the particles over time.

### Code Structure

The code is written in C++ and consists of the following components:

1. **Vector3**: This class represents a 3D vector and provides various operations for vector arithmetic, such as addition, subtraction, scaling, dot product, cross product, magnitude, and normalization.

2. **Particle**: This struct defines a particle object, which has properties including mass, position (a Vector3), and velocity (a Vector3). Particles interact with each other through collisions.

3. **updateParticles**: This function updates the state of the particles based on the elapsed time (deltaTime). It applies gravitational force to each particle, updates their velocities and positions, and handles collisions between particles using an impulse-based collision response.

4. **main**: The main function initializes a vector of particles and performs the simulation by repeatedly calling the `updateParticles` function. It also prints the position of each particle after each iteration.

### Usage

To use this code, you can follow these steps:

1. Create an empty C++ project and add the code to a source file (e.g., `main.cpp`).

2. Compile and run the program. The simulation will update the particle positions and print them to the console for each iteration.

3. You can modify the initial parameters of the particles, such as mass, position, and velocity, to observe different behaviors in the simulation.

4. Adjust the simulation parameters, such as the gravitational constant and the time step (deltaTime), to achieve the desired simulation characteristics.

### Further Improvements

The code provided serves as a basic framework for particle simulations. However, it can be extended and improved in several ways, such as:

- Adding additional forces or constraints, such as friction, air resistance, or collision with fixed objects.
- Implementing more sophisticated collision detection algorithms, like bounding volume hierarchies or spatial partitioning.
- Utilizing a more efficient integration method, such as Verlet integration or Runge-Kutta methods, for improved accuracy and stability.
- Enhancing the visualization of the simulation by using a graphics library or integrating with a physics engine for real-time rendering.

These improvements would provide a more realistic and visually appealing particle simulation.
Adjust the simulation parameters, such as the gravitational constant and the time step (deltaTime), to achieve the desired simulation characteristics.