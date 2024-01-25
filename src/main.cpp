void
shmBuoyancy(double particleDensity, double particleVolume, double fluidDensity,
        double containerDepth, double particleStartPosition);

#include <iostream>

int main()
{
    shmBuoyancy(800, 1, 1000, 1, -0.5);
    std::cout << "\n";
    shmBuoyancy(2712, 1, 13500, 1, -0.5);
    std::cout << "\n";
    shmBuoyancy(800, 1, 1000, 1, 1);
    return 0;
}
