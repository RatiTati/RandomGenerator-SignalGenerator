#ifndef _RANDOMGENERATOR_HH_
#define _RANDOMGENERATOR_HH_

class RandomGenerator {
public:
    RandomGenerator(unsigned int seed = 0);
    double GetRndm(); //abrunebs random 0-1 shroris
    double GetRndm(double min, double max);
    double GetGaus(double mean, double sigma);
    double GetGaus2(double mean, double sigma, int n = 20);
};

#endif
