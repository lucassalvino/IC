#ifndef GENERATION_H
#define GENERATION_H
#include "utility.h"
#include "chromosome.h"

TEMPLATE
class Generation{
public:
    int getIdGeneration(){
        return idGeneration;
    }

    void setIdGeneration(int value){
        idGeneration =  value;
    }

    double getEvaluationSum(){
        return evaluationSum;
    }

    void setEvaluationSum(double value){
        evaluationSum = value;
    }

    Chromosome<TIPO> getBest(){
        return best;
    }

    void setBest(const Chromosome<TIPO> value){
        best = value;
    }

private:
    double evaluationSum;
    int idGeneration;
    Chromosome<TIPO> best;
};
#endif // GENERATION_H
