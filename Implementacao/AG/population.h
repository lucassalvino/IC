#ifndef POPULATION_H
#define POPULATION_H

#include <stdlib.h>
#include <stdio.h>
#include "chromosome.h"
#include "calculateevaluation.h"
#include <list>
#include <iostream>
#include <random>
#include <time.h>
#include "utility.h"
using namespace std;

TEMPLATE
class Population
{
public:
    Population(GenerateGene<TIPO> *ge,CalculateEvaluation<TIPO>*calc);
    ~Population();
    void evaluationAll();
    void initPopulation(int sizePopulation, int numGenes);
    void printChomosomeOfPopulation();
private:
    double evaluationSum;
    void updateEvaluationSum();
    Chromosome<TIPO> roulette();
    list<Chromosome<TIPO> > chromosomes;
    GenerateGene<TIPO>* getGene;
    CalculateEvaluation<TIPO>* calculateEvaluation;
};

#endif // POPULATION_H
