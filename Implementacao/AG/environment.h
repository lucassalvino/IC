#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <iostream>
using namespace std;
#include <stdio.h>
class Environment{
public:
    Environment(){
        rateDecreaseCrossOver = 0;
        rateChange = -1;
        rateCrossOver = -1;
        generationNumberNotFixedRateCrossOver = -1;
    }

    int getGenerationNumberNotFixedRateCrossOver(){
        return generationNumberNotFixedRateCrossOver;
    }

    int setGenerationNumberNotFixedRateCrossOver(int value){
        if (value < 0)
            throw string("O valor de generationNumberNotFixedRateCrossOver não pode ser negativo");
        generationNumberNotFixedRateCrossOver = value;
    }

    double GetRateDecreaseCrossOver(){
        return rateDecreaseCrossOver;
    }

    void setRateDecreaseCrossOver(double value){
        rateDecreaseCrossOver = value;
    }

    double getRateChange(){
        return rateChange;
    }

    void setRateChange(double value){
        if(value > 1.0) printf("[CUIDADO] A taxa de mutação é maior que 100 por cento.");
        rateChange = value;
        rateCrossOver = 1 - rateChange; //rateCrossOver recebe a diferenca do valor setado de 100%(1)
    }

    double getRateCrossOver(){
        return rateCrossOver;
    }

    void setRateCrossOver(double value){
        if(value > 1.0) printf("[CUIDADO] A taxa de crossOver é maior que 100 por cento.");
        rateCrossOver = value;
        rateChange = 1 - rateCrossOver; //rateChange recebe a diferenca do valor setado de 100%(1)
    }

    string ToString(){
        char aux [90]; *aux = 0;
        sprintf(aux,"rateChange = %lf, rateCrossOver = %lf",rateChange,rateCrossOver);
        return string(aux);
    }

private:
    //////////////////////////////////////////////////////////////////////////////
    /*As taxas de mutação rateChange e a taxa de CrossOver rateCrossOver, devem possuir somatio = a 100, representando a porcentagem de execução
    total dos operadores geneticos. Isso é feito automaticamente ao setar um dos valores correspondentes, o outro é preenchido com a diferença do mesmo*/
    double rateChange;
    double rateCrossOver;
    double rateDecreaseCrossOver;/*o valor que será decrementado da taxa de cruzamento e acrescentado na taxa mutação a partir de generationNumberNotFixedRateCrossOver*/
    int generationNumberNotFixedRateCrossOver;
    //////////////////////////////////////////////////////////////////////////////
};

#endif // ENVIRONMENT_H
