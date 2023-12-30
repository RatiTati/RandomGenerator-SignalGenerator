#include <iostream>
#include <stdlib.h>
#include "SignalGenerator.hh"
#include <new>
#include <cmath>

SignalGenerator::SignalGenerator(){
    Signal = Time = 0x0;
    DC = Sigma = 0;  //aq setterebit shecvale
}

void SignalGenerator::AddHarmonics(double A, double f, double p){
    Harmonics har;
    har.A = A;
    har.f = f;
    har.p = p;
    hData.push_back(har);
}

void SignalGenerator::SetDC(double dc){this->DC = dc;}

void SignalGenerator::SetNoise(double sigma){this->Sigma = sigma;}

void SignalGenerator::Generate(double t, unsigned long np){
    if(Time == 0x0 && Signal == 0x0){
        NP = np;
        try{
            Signal = new double[np];
            Time = new double[np];
        }
        catch(std::bad_alloc& ba){
            if(Signal == 0x0){
                std::cerr << "bad_alloc caught for Signal: "<<ba.what() <<std::endl;
                return;
            }else{
                std::cerr << "bad_alloc caught for Time: "<<ba.what() <<std::endl;
                delete [] Signal;
                return;
            }
        }

        for(int i=0; i<np; ++i){
            Time[i] = t/(np -1) * i;
        }

        for(int i=0; i<np; ++i){
            for(int j=0; j<hData.size(); ++j){
                if(np/(2*t)>hData[j].f){
                    Signal[i] += hData[j].A * sin(2*M_PI*hData[j].f*Time[i] + hData[j].p);
                }else
                    Signal[i] = 0;
                }
            Signal[i]+= DC + GetGaus(0., Sigma); //+noise
        }
    }
}


void SignalGenerator::Generate(double t, double dt){
    unsigned int np = t/dt + 1;
    Generate(t, (unsigned long)np);
}

SignalGenerator::~SignalGenerator(){
    if(Signal!=0x0){
        for(int i=0; i<NP; ++i)
            delete [] &(Signal[i]);
    }
    delete [] Signal;
    if(Time!=0x0){
    for(int i=0; i<NP; ++i)
        delete [] &(Time[i]);
    }
    delete [] Time;
}
