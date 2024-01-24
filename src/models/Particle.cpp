#include "Particle.h"

const double g = -9.80;

Particle::Particle(double m, double vol, double rho, double x0, double x1,
        double x2, double vel, double a)
{
    if (rho==-1) {
        setMass(m);
        setVolume(vol);
        setDensity(m/vol);
    }
    else if (vol==-1) {
        setMass(m);
        setDensity(rho);
        setVolume(m/rho);
    }
    else if (m==-1) {
        setVolume(vol);
        setDensity(rho);
        setMass(rho*vol);
    }
    setPosition(x0, x1, x2);
    setVelocity(vel);
    setAcceleration(a);
}
void Particle::setMass(double m)
{
    if (m>=0) {
        mass = m;
    }
    else {
        mass = 0;
    }
}
void Particle::setVolume(double v)
{
    if (v>=0) {
        volume = v;
    }
    else {
        volume = 0;
    }
}
void Particle::setDensity(double rho)
{
    if (rho>=0) {
        density = rho;
    }
    else {
        density = 0;
    }
}
void Particle::setPosition(double x0, double x1, double x2)
{
    position = {x0, x1, x2};
}
void Particle::setVelocity(double v)
{
    velocity = v;
}
void Particle::setAcceleration(double a)
{
    acceleration = a;
}
double Particle::getMass() const
{
    return mass;
}
double Particle::getVolume() const
{
    return volume;
}
double Particle::getDensity() const
{
    return density;
}
std::vector<double> Particle::getPosition() const
{
    return position;
}
double Particle::getVelocity() const
{
    return velocity;
}
double Particle::getAcceleration() const
{
    return acceleration;
}
double Particle::getForceGravity() const
{
    return forceGravity;
}
void Particle::updateForceGravity()
{
    forceGravity = mass*g;
}
