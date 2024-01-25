#include <iostream>
#include <cmath>
#include "FluidContainer.h"

const double g = -9.80;

FluidContainer::FluidContainer(Particle& p, Fluid& f)
{
    particle = &p;
    fluid = &f;
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<2; j++) {
            boundary[i][j] = 0;
        }
    }
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
    particle->setPosition(x0, x1, x2);
}
void FluidContainer::setBoundary_x(double left, double right)
{
    boundary[0][0] = left;
    boundary[0][1] = right;
}
void FluidContainer::setBoundary_y(double bottom, double top)
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
double FluidContainer::calculateParticleAcceleration()
{
    return g-((fluid->getDensity()*particle->getVolume()*g)/particle->getMass());
}
double FluidContainer::calculateParticleVelocity
        (double time)
{
    return (particle->getAcceleration())*time;
}
double
FluidContainer::calculateParticlePosition(double initialPosition, double time)
{
    return particle->getAcceleration()*time*time*0.5+initialPosition;
}
void FluidContainer::setParticleAcceleration()
{
    particle->setAcceleration(calculateParticleAcceleration());
}
void FluidContainer::setParticleVelocity(double time)
{
    particle->setVelocity(calculateParticleVelocity(time));
}
void FluidContainer::setParticlePosition(double initialPosition, double time)
{
    particle->setPosition(0, calculateParticlePosition(initialPosition, time),
            0);
}
void FluidContainer::updateKinematics(double initialPosition, double time)
{
    setParticleAcceleration();
    // performance, acceleration doesn't need to be
    // calculated every time
    setParticleVelocity(time);
    setParticlePosition(initialPosition, time);
}
