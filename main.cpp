#include <iostream>
#include "RandomGenerator.hh"
#include "SignalGenerator.hh"
#include <Histo.hh>
#include <Graph.hh>

using namespace std;

int main(){
    Histo myH("MyHisto", 100, -5, 40);
    RandomGenerator r;
    for(int i=0; i<100000; i++){
        myH.Fill(r.GetGaus2(12, 4));
    }
    double mean = myH.GetMean();
    cout<<"mean of histo: "<<mean<<endl;
    double sigma = myH.GetRMS();
    cout<<"mean of sigma: "<<sigma<<endl;
    myH.Draw(1);

    Graph myG("MyGraph");
    SignalGenerator sg;
    sg.AddHarmonics(10, 0.2, 0);
    sg.AddHarmonics(6, 0.3, 0);
    sg.SetNoise(2);
    sg.Generate(20, (unsigned long)400);
    for(int i=0; i<sg.getNpoints(); i++){
        myG.AddPoint(sg.getTime()[i], sg.getSignal()[i]);
    }
    myG.Draw(0);
}
