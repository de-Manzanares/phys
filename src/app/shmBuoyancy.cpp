#include <iostream>
#include <iomanip>
#include <cmath>
#include "FluidContainer.h"

double const g = -9.80;
void
shmBuoyancy(double particleDensity, double particleVolume, double fluidDensity,
        double containerDepth, double particleStartPosition)
{
    FluidContainer container;

    container.particle_set_density(particleDensity);
    container.particle_set_volume(particleVolume);
    container.particle_set_mass(particleDensity*particleVolume);
    container.fluid_set_density(fluidDensity);
    container.set_boundary_y(-std::abs(containerDepth), 0);
    container.particle_set_position(0, particleStartPosition, 0);

    container.particle_calc_a_submerged();
    double v0 = 0;
    double p0 = particleStartPosition;
    double t = 0;
    double INCREMENT = 0.01;
    double boundaryTime = (
            sqrt(
                    (pow(container.particle_get_velocity(), 2))
                            -2*container.particle_get_acceleration()*p0)
                    -container.particle_get_velocity())
            /container.particle_get_acceleration();
    double boundaryVelocity = (
            container.particle_get_acceleration()*boundaryTime
                    +v0);

    while (container.particle_get_position()[1]<0 && t<=boundaryTime) {
        container.particle_calc_velocity(t, v0);
        container.particle_calc_position(t, v0, p0);
        std::cout << container.particle_get_position()[1] << ", ";
        t += INCREMENT;
    }

    container.particle_calc_a_in_air();
    container.particle_set_position(0);
    v0 = boundaryVelocity;
    p0 = 0;
    t = 0;
    boundaryTime = -2*(boundaryVelocity/container.particle_get_acceleration());
    //std::cout << "\n" << boundaryTime << "\n";

    while (container.particle_get_position()[1]>=0 && t<=boundaryTime) {
        container.particle_calc_velocity(t, v0);
        container.particle_calc_position(t, v0, p0);
        std::cout << container.particle_get_position()[1] << ", ";
        t += INCREMENT;
    }

    container.particle_calc_velocity(boundaryTime, v0);
    v0 = container.particle_get_velocity();
    container.particle_calc_a_submerged();
    container.particle_set_position(0);
    p0 = 0;
    t = 0;
    boundaryTime = 2*(boundaryVelocity/container.particle_get_acceleration());
    //std::cout << "\n" << boundaryTime << "\n";

    while (container.particle_get_position()[1]<=0 && t<=boundaryTime) {
        container.particle_calc_velocity(t, v0);
        container.particle_calc_position(t, v0, p0);
        std::cout << container.particle_get_position()[1] << ", ";
        t+=INCREMENT;
    }
}
