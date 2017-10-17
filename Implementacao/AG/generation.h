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

    double getMutationRate(){
        return mutationRate;
    }

    void setMutationRate(double value){
        mutationRate = value;
    }

    double getEvaluationSum(){
        return evaluationSum;
    }

    void setEvaluationSum(double value){
        evaluationSum = value;
    }

private:
    double evaluationSum;
    int idGeneration;
    double mutationRate;
};
#endif // GENERATION_H
