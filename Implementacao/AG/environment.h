#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <iostream>
using namespace std;
#include <stdio.h>
class Environment{
public:
    double getRateChange(){
        return rateChange;
    }

    void setRateChange(double value){
        rateChange = value;
    }
    string ToString(){
        char aux [90]; *aux = 0;
        sprintf(aux,"rateChange = %lf",rateChange);
        return string(aux);
    }

private:
    double  rateChange;
};

#endif // ENVIRONMENT_H
