#ifndef CALCULATEEVALUATION_H
#define CALCULATEEVALUATION_H
#include "chromosome.h"
TEMPLATE
class CalculateEvaluation{
public:
    virtual double calculateEvaluation(Chromosome<TIPO> value,int init, int final){return 0;}
    virtual double calculateEvaluation(Chromosome<TIPO> value){return 0;}
    virtual double getEvaluation(Chromosome<TIPO>& value){return 0;}
};

#endif // CALCULATEEVALUATION_H
