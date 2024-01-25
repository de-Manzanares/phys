#include <iostream>
#include <iomanip>
#include "FluidContainer.h"

double const g = -9.80;
void
shmBuoyancy(double particleDensity, double particleVolume, double fluidDensity,
        double containerDepth, double particleStartPosition)
{
    const int MODE = 0;

    Particle particle;
    Fluid fluid(fluidDensity);

    particle.setDensity(particleDensity);
    particle.setVolume(particleVolume);
    particle.setMass(particleDensity*particleVolume);

    FluidContainer container(particle, fluid);

    container.setBoundary_y(-(std::abs(containerDepth)), 0);
    container.setParticlePosition(0, particleStartPosition, 0);

    double t = 0;
    std::cout << std::fixed << std::showpoint << std::setprecision(5);
    while (t<=2) {
        container.updateKinematics(t);
        if (MODE==0) {
            std::cout << "t = " << std::setw(10) << t
                      << "\ta = " << std::setw(10) << particle.getAcceleration()
                      << "\tv = " << std::setw(10) << particle.getVelocity()
                      << "\tx = " << std::setw(10) << particle.getPosition()[1]
                      << "\n";
        }
        if (MODE==1) {
            std::cout << particle.getPosition()[1] << ", ";
        }

        t += 0.01;

    }
}