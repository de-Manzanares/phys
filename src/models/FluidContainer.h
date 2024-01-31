#include "Fluid.h"
#include "Particle.h"

#ifndef PHYS_CONTAINER_H
#define PHYS_CONTAINER_H

class FluidContainer {
public:
    FluidContainer();
    ~FluidContainer();
    void printParticlePosition() const;
    void setParticlePosition(double x0, double x1, double x2);
    void setBoundary_x(double left, double right);
    void set_boundary_y(double bottom, double top);
    void setBoundary_z(double back, double front);
    double getBoundary_x_left() const;
    double getBoundary_x_right() const;
    double getBoundary_y_bottom() const;
    double getBoundary_y_top() const;
    double getBoundary_z_back() const;
    double getBoundary_z_front() const;
    void particle_set_density(double d);
    void particle_set_volume(double vol);
    void particle_set_mass(double m);
    void set_fluid_density(double d);
    void particle_set_position(double x0, double x1, double x2);
    void particle_set_position(double x1);
    std::vector<double> particle_get_position();
    void particle_calc_a_submerged();
    void particle_calc_a_in_air();
    void particle_calc_velocity(double time, double v0);
    double particle_get_velocity();
    double particle_get_acceleration();
    void particle_calc_position(double time, double v0, double p0);
    double pressure_at_depth_h(double referencePressure, double h);
private:
    Particle* particle;
    Fluid* fluid;
    double boundary[3][2];
    double initialVelocity;
    double initialPosition;
    bool submerged;
};

#endif //PHYS_CONTAINER_H
