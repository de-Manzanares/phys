#ifndef PHYS_PARTICLE_H
#define PHYS_PARTICLE_H

class Particle {
public:
    void setMass(double m);
    void setVolume(double v);
    void setDensity(double rho);
    void setPosition(double s);
    void setVelocity(double v);
    void setAcceleration(double a);
    double getMass() const;
    double getVolume() const;
    double getDensity() const;
    double getPosition() const;
    double getVelocity() const;
    double getAcceleration() const;

private:
    double mass;
    double volume;
    double density;
    double position;
    double velocity;
    double acceleration;
};

#endif //PHYS_PARTICLE_H
