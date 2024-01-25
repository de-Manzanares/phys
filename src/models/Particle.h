#include <vector>

#ifndef PHYS_PARTICLE_H
#define PHYS_PARTICLE_H

class Particle {
public:
    Particle();
    void setMass(double m);
    void setVolume(double v);
    void setDensity(double rho);
    void set_position(double x1);
    void set_position(double x0, double x1, double x2);
    void set_velocity(double v);
    void set_acceleration(double a);
    double getMass() const;
    double get_volume() const;
    double getDensity() const;
    std::vector<double> getPosition() const;
    double get_velocity() const;
    double get_acceleration() const;

private:
    double mass;
    double volume;
    double density;
    std::vector<double> position;
    double velocity;
    double acceleration;
};

#endif //PHYS_PARTICLE_H
