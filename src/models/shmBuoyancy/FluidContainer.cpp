#include <iostream>
#include <cmath>
#include "FluidContainer.h"

const double g = -9.80;

FluidContainer::FluidContainer()
{
    particle = new Particle;
    fluid = new Fluid;

    for (int i = 0; i<3; i++) {
        for (int j = 0; j<2; j++) {
            boundary[i][j] = 0;
        }
    }
    initialVelocity = 0;
}
FluidContainer::~FluidContainer()
{
    delete particle;
    delete fluid;
}
void FluidContainer::printParticlePosition() const
{
    std::vector<double> particlePosition = particle->getPosition();
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
void FluidContainer::setParticlePosition(double x0, double x1, double x2)
{
    particle->set_position(x0, x1, x2);
}
void FluidContainer::setBoundary_x(double left, double right)
{
    boundary[0][0] = left;
    boundary[0][1] = right;
}
void FluidContainer::set_boundary_y(double bottom, double top)
{
    boundary[1][0] = bottom;
    boundary[1][1] = top;
}
void FluidContainer::setBoundary_z(double back, double front)
{
    boundary[2][0] = back;
    boundary[2][1] = front;
}
double FluidContainer::getBoundary_x_left() const
{
    return boundary[0][0];
}
double FluidContainer::getBoundary_x_right() const
{
    return boundary[0][1];
}
double FluidContainer::getBoundary_y_bottom() const
{
    return boundary[1][0];
}
double FluidContainer::getBoundary_y_top() const
{
    return boundary[1][1];
}
double FluidContainer::getBoundary_z_back() const
{
    return boundary[2][0];
}
double FluidContainer::getBoundary_z_front() const
{
    return boundary[2][1];
}
void FluidContainer::particle_set_density(double d)
{
    particle->setDensity(d);
}
void FluidContainer::particle_set_volume(double vol)
{
    particle->setVolume(vol);
}
void FluidContainer::particle_set_mass(double m)
{
    particle->setMass(m);
}
void FluidContainer::fluid_set_density(double d)
{
    fluid->setDensity(d);
}
void FluidContainer::particle_set_position(double x0, double x1, double x2)
{
    particle->set_position(x0, x1, x2);
}
std::vector<double> FluidContainer::particle_get_position()
{
    return particle->getPosition();
}
void FluidContainer::particle_calc_a_submerged()
{
    particle->set_acceleration(
            g-((fluid->get_density()*particle->get_volume()*g)
                    /particle->getMass())
    );
}
void FluidContainer::particle_calc_velocity(double time, double v0)
{
    particle->set_velocity(
            particle->get_acceleration()*time
                    +v0
    );
}
double FluidContainer::particle_get_velocity()
{
    return particle->get_velocity();
}
void FluidContainer::particle_calc_position(double time, double v0, double p0)
{
    particle->set_position(
            particle->get_acceleration()*((time*time)/2)
                    +v0*time
                    +p0
    );
}
double FluidContainer::particle_get_acceleration()
{
    return particle->get_acceleration();
}
void FluidContainer::particle_calc_a_in_air()
{
    particle->set_acceleration(
            g
    );
}
void FluidContainer::particle_set_position(double x1)
{
    particle->set_position(x1);
}

