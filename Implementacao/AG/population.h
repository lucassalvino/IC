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
#include "operators.hpp"
#include "environment.h"

using namespace std;

TEMPLATE
class Population
{
public:
    Population(GenerateGene<TIPO> *ge,CalculateEvaluation<TIPO>*calc, Operators<TIPO>* operato);
    ~Population();
    void evaluationAll();
    void initPopulation(int sizePopulation, int numGenes);
    void printChomosomeOfPopulation();
    Chromosome<TIPO> roulette();
    Chromosome<TIPO> getBestChromosome();
    double getEvaluationSum();
    int getIdGeneration();
    void setIdGeneration(int value);
    void CalculateNextPopulation();
    void nextPopulation();
    Environment getEnvironment();
    void setEnvironment(Environment value);
    int getNumChromosomes();
    Chromosome<TIPO> getChromosomeAt(int index);
private:
    int idGeneration;
    double evaluationSum;
    void updateEvaluationSum();
    list<Chromosome<TIPO> > chromosomes;
    list<Chromosome<TIPO> > new_chromosomes;
    GenerateGene<TIPO>* getGene;
    CalculateEvaluation<TIPO>* calculateEvaluation;
    Operators<TIPO>* operators;
    Environment environment;
};

#endif // POPULATION_H
