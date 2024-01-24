#include "Fluid.h"
#include "Particle.h"

#ifndef PHYS_CONTAINER_H
#define PHYS_CONTAINER_H

class FluidContainer {
public:
    FluidContainer(Particle& p, Fluid& f);
    void printParticlePosition() const;
private:
    Particle particle;
    Fluid fluid;
};

#endif //PHYS_CONTAINER_H
