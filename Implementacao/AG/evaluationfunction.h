#ifndef EVALUATIONFUNCTION_H
#define EVALUATIONFUNCTION_H
#include "chromosome.h"

template <class TYPE>
class EvaluationFunction
{
public:
    virtual double calculateEvaluation(Chromosome<TYPE> chromosome){
        return 0;
    }
    virtual double calculateEvaluation(){
        return 0;
    }
};
#endif // EVALUATIONFUNCTION_H
