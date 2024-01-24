#include <iostream>
#include "FluidContainer.h"

void shmBuoyancy()
{
    Particle particle(1, -1, 0.5);
    Fluid fluid;
    FluidContainer container(particle, fluid);
    container.printParticlePosition();
    std::cout << particle.getVolume();
}