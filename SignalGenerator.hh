#ifndef _SIGNALGENERATOR_HH_
#define _SIGNALGENERATOR_HH_

#include <vector>
#include "RandomGenerator.hh"

struct Harmonics{
    double A, f, p; //amplitude, frequency, phase
};

class SignalGenerator : public RandomGenerator{
std::vector<Harmonics> hData;
double* Signal;
double* Time;
double DC, Sigma;
unsigned long NP;
public:
    SignalGenerator();
    void AddHarmonics(double A, double f, double p);
    void SetDC(double dc);
    void SetNoise(double sigma);
    void Generate(double t, unsigned long np);
    void Generate(double t, double dt);
    double* getSignal(){return Signal;}
    double* getTime(){return Time;}
    unsigned long getNpoints(){return NP;}
    ~SignalGenerator();
};

#endif
