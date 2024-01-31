#include <iostream>
#include <iomanip>
#include <cmath>
#include "StandingWavesOnAString.h"

void StandingWavesOnAString::list_node_properties_massless(int nodes)
{
    std::cout << std::fixed << std::showpoint << std::setprecision(5)
              << "Frequency: " << vibratorFrequency << " Hz" << "\n"
              << "String Length: " << stringLength << " m" << "\n\n";
    for (int i = 1; i<=nodes; i++) {
        std::cout << "Harmonic: " << std::setw(4) << i
                  << "\t\tWavelength: "
                  << std::setw(10)
                  << (2*stringLength)/i << " m"
                  << "\t\tWave Velocity: "
                  << std::setw(10)
                  << (vibratorFrequency*(2*stringLength)/i) << " m/s"
                  << "\n";

    }
    std::cout << std::endl;
}
void StandingWavesOnAString::list_node_properties_fixed_linear_density(
        int nodes)
{
    std::cout << "Frequency: " << vibratorFrequency << " Hz" << "\n"
              << "String Length: " << stringLength << " m" << "\n"
              << "Linear Density: "
              << std::setprecision(8) << linearDensity << " kg/m" << "\n\n";
    for (int i = 1; i<=nodes; i++) {
        std::cout << "Harmonic: " << std::setw(4) << i
                  << "\t\tWavelength: "
                  << std::setw(10)
                  << (2*stringLength)/i << " m"
                  << "\t\tWave Velocity: "
                  << std::setw(10)
                  << (vibratorFrequency*(2*stringLength)/i) << " m/s"
                  << "\t\tTension: "
                  << std::setw(10)
                  << pow((vibratorFrequency*(2*stringLength)/i), 2)
                          *linearDensity
                  << " N"
                  << "\t\tMass on pulley: "
                  << std::setw(10)
                  << (pow((vibratorFrequency*(2*stringLength)/i), 2)
                          *linearDensity)/9.80
                  << " kg"
                  << "\n";
    }
}
