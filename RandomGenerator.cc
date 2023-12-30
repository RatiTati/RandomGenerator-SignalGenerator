#include "RandomGenerator.hh"
#include <stdlib.h>
#include <ctime>
#include <cmath>
using namespace std;

RandomGenerator::RandomGenerator(unsigned int seed){
    srand(seed);
}

double RandomGenerator::GetRndm(){
    return (double)rand()/RAND_MAX;
}

double RandomGenerator::GetRndm(double min, double max){
    double r = GetRndm();
    return (r*(max - min)+ min);
}

double RandomGenerator::GetGaus2(double mean, double sigma, int n){
    double sum;
    for(int i=0; i<n; ++i){
        double x = GetRndm();
        sum+=x;
    }
    sum-=(double)n/2;
    sum/=sqrt(n/12);
    return sum*sigma+mean;
}

double RandomGenerator::GetGaus(double mean, double sigma){
    static int k = 0;
    static double temp;
    if(k%2==0){
        double u1 = GetRndm(), u2 = GetRndm();
        double z1 = sqrt(-2*log(u1)) * sin(2*M_PI*u2);
        double z2 = sqrt(-2*log(u1)) * cos(2*M_PI*u2);
        temp = z2;
        k++;
        return z1*sigma + mean;
    }else{
        k++;
        return temp*sigma + mean;
    }
}
