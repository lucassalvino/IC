#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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
    int randomNumPossion(double lambida){/*funcao feita baseado no encontro da IC*/
        /**retorna um numreo entre [0,2] com frequencia determinada por lambida e os parametros de fRand*/
        double y = exp(lambida);
        double x = 1;
        int k = -1;
        do{
            x *= fRand(1,2);
            k++;
        }
        while(x<=y);
        //printf("verifica:x [%lf] y[%lf] k[%d]\n",x,y,k);
        return k;
    }
};

#endif // UTILITY_H
