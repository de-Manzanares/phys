void
shmBuoyancy(double particleDensity, double particleVolume, double fluidDensity,
        double containerDepth, double particleStartPosition);

int main()
{
    shmBuoyancy(900, 1, 1000, 1, -0.5);
    return 0;
}
