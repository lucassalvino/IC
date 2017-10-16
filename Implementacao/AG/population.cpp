#include "population.h"
TEMPLATE
Population<TIPO>::Population()
{
    getGene = new GenerateGene<TIPO>();
}

TEMPLATE
Population<TIPO>::Population(GenerateGene<TIPO> *ge)
{
    getGene = ge;
}

TEMPLATE
Population<TIPO>::~Population()
{
    delete [] getGene;
}

TEMPLATE
void Population<TIPO>::initPopulation(int sizePopulation, int numGenes)
{
    for(int i = 0; i<sizePopulation; i++){
        Chromosome<int> add;
        add.generateRandom(this->getGene,numGenes);
        this->chromosomes.push_back(add);
    }
}

TEMPLATE
void Population<TIPO>::printChomosomeOfPopulation()
{
    for(list<Chromosome<int> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
        int * gene = it->getGene();
        for(int i=0; i<it->getNumberOfElements(); i++)
            printf("%d ", gene[i]);
        printf("\n");
    }
}
