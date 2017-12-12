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
        generationNumberNotFixedRateCrossOver = 0;
    }

    int getGenerationNumberNotFixedRateCrossOver(){
        return generationNumberNotFixedRateCrossOver;
    }

    void setGenerationNumberNotFixedRateCrossOver(int value){
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
        if(rateChange < 0)
            throw string("A taxa de Mutação (rateChange) ainda não foi setada");
        return rateChange;
    }

    void setRateChange(double value){
        if(value > 1.0) printf("[CUIDADO] A taxa de mutação é maior que 100 por cento.");
        rateChange = value;
        rateCrossOver = 1 - rateChange; //rateCrossOver recebe a diferenca do valor setado de 100%(1)
    }

    double getRateCrossOver(){
        if(rateCrossOver<0)
            throw string("A taxa de CrossOver (rateCrossOver) ainda nao foi setada");
        return rateCrossOver;
    }

    void setRateCrossOver(double value){
        if(value > 1.0) printf("[CUIDADO] A taxa de crossOver é maior que 100 por cento.");
        rateCrossOver = value;
        rateChange = 1 - rateCrossOver; //rateChange recebe a diferenca do valor setado de 100%(1)
    }

    void updateValues(){
        setRateCrossOver(getRateCrossOver()-GetRateDecreaseCrossOver());
        printf("\t[INFO] Realizado update para os valores do ambiente. Novos Valores: \n\t\t%s\n", this->ToString().c_str());
    }

    string ToString(){
        char aux [255]; *aux = 0;
        sprintf(aux,"rateChange = %.3lf, rateCrossOver = %.3lf, rateDecreaseCrossOver = %.3lf, generationNumberNotFixedRateCrossOver = %d",rateChange,rateCrossOver,rateDecreaseCrossOver,generationNumberNotFixedRateCrossOver);
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
