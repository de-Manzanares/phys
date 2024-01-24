#include <iostream>
#include "FluidContainer.h"

const double g = -9.80;

FluidContainer::FluidContainer(Particle& p, Fluid& f)
{
    particle = p;
    fluid = f;
}
void FluidContainer::printParticlePosition() const
{
    std::vector<double> particlePosition = particle.getPosition();
    std::cout << "(";
    for (int i = 0; i<3; i++) {
        std::cout << particlePosition[i];
        if (i<2) {
            std::cout << ", ";
        }
        else {
            std::cout << ")\n";
        }
    }
}
