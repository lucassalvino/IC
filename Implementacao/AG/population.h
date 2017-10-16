#ifndef POPULATION_H
#define POPULATION_H

#include <stdlib.h>
#include <stdio.h>
#include "chromosome.h"
#include <list>
#include <iostream>
using namespace std;

#define TEMPLATE template<class TIPO>

TEMPLATE
class Population
{
public:
    Population();
    Population(GenerateGene<TIPO> *ge);
    ~Population();
    void initPopulation(int sizePopulation, int numGenes);
    void printChomosomeOfPopulation();
private:
    list<Chromosome<TIPO> > chromosomes;
    GenerateGene<TIPO>* getGene;
};

#endif // POPULATION_H
