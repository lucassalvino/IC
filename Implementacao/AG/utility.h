#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Utility{
public:
    static double fRand(double fMin, double fMax){ /*https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c*/
        srand(time(0));
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }
};

#endif // UTILITY_H
