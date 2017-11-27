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
class GenerateRandomChromosome{
public:
    virtual Chromosome<TIPO> GenerateChromosome(int numGenes, int ID){ numGenes = numGenes; ID = ID; throw std::string("Função ainda não definida");}
};

TEMPLATE
class Population
{
public:
    Population(GenerateGene<TIPO> *ge, CalculateEvaluation<TIPO>*calc, Operators<TIPO>* operatos, GenerateRandomChromosome<TIPO>* generateCromossome);
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
    int getNumGene();
    int getSizePopulation();
    double getDefaultDeviation();
private:
    int idGeneration;
    double evaluationSum;
    double defaultDeviation;
    void updateEvaluationSum();
    list<Chromosome<TIPO> > chromosomes;
    list<Chromosome<TIPO> > new_chromosomes;
    GenerateGene<TIPO>* getGene;
    CalculateEvaluation<TIPO>* calculateEvaluation;
    Operators<TIPO>* operators;
    Environment environment;
    GenerateRandomChromosome<TIPO>* getChromossome;
    int sizePopulation;
    int numGenes;
};

#endif // POPULATION_H
