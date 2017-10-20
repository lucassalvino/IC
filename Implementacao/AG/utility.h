#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

class Utility{
public:
    static double fRand(double fMin, double fMax){ /*https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c*/
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    int getNumberGeneForChormosome(float init,float final, float precision){ /* retorna quantos bits serao necessarios para representar */
        float aux = ((init - final)/precision)+1;
        return (int) log2(aux);
    }
};

#endif // UTILITY_H
