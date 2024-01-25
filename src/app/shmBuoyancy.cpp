#include <iostream>
#include "FluidContainer.h"

double const g = -9.80;
void
shmBuoyancy(double particleDensity, double particleVolume, double fluidDensity,
        double containerDepth, double particleStartPosition)
{
    Particle particle;
    Fluid fluid(fluidDensity);

    particle.setDensity(particleDensity);
    particle.setVolume(particleVolume);
    particle.setMass(particleDensity*particleVolume);

    FluidContainer container(particle, fluid);

    container.setBoundary_y(-(std::abs(containerDepth)), 0);
    container.setParticlePosition(0, particleStartPosition, 0);

    container.printParticlePosition();
    std::cout << "Fluid density: " << fluid.getDensity() << "\n";
    std::cout << "Particle volume: " << particle.getVolume() << "\n";
    std::cout << "Particle mass: " << particle.getMass() << "\n";

    std::cout << "What the acceleration should be: " << g-((fluid.getDensity()
            *particle.getVolume()*g)/particle
            .getMass());
    std::cout << "\nAcceleration before calc: "
              << particle.getAcceleration() << "\n";

    container.setParticleAcceleration();
    std::cout << "Acceleration after calc: "
              << particle.getAcceleration() << "\n";

    std::cout << "What it should be: "
              << container.calculateParticleAcceleration() << "\n";

    // double t = 0;
    // while (t<=2) {
    //     container.updateKinematics(particleStartPosition, t);
    //     std::cout << particle.getAcceleration() << "\n";
    //     std::cout << particle.getVelocity() << "\n";
    //     std::cout << particle.getPosition()[1] << "\n";
    //     t += 0.1;
    // }
}