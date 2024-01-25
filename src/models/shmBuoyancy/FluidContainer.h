#include "Fluid.h"
#include "Particle.h"

#ifndef PHYS_CONTAINER_H
#define PHYS_CONTAINER_H

class FluidContainer {
public:
    FluidContainer(Particle& p, Fluid& f);
    void printParticlePosition() const;
    void setParticlePosition(double x0, double x1, double x2);
    void setBoundary_x(double left, double right);
    void setBoundary_y(double bottom, double top);
    void setBoundary_z(double back, double front);
    double getBoundary_x_left() const;
    double getBoundary_x_right() const;
    double getBoundary_y_bottom() const;
    double getBoundary_y_top() const;
    double getBoundary_z_back() const;
    double getBoundary_z_front() const;
    double calculateParticleAcceleration();
    double calculateParticleVelocity(double time);
    double calculateParticlePosition(double initialPosition, double time);
    void setParticleAcceleration();
    void setParticleVelocity(double time);
    void setParticlePosition(double initialPosition, double time);
    void updateKinematics(double initialPosition, double time);

private:
    Particle *particle;
    Fluid *fluid;
    double boundary[3][2];
};

#endif //PHYS_CONTAINER_H
