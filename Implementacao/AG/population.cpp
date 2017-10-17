#include "population.h"

TEMPLATE
Population<TIPO>::Population(GenerateGene<TIPO> *ge,CalculateEvaluation<TIPO>*calc)
{
    getGene = ge;
    calculateEvaluation = calc;
}

TEMPLATE
Population<TIPO>::~Population()
{
    delete [] getGene;
    delete [] calculateEvaluation;
}

TEMPLATE
void Population<TIPO>::evaluationAll()
{
    this->evaluationSum = 0;
    for(list<Chromosome<int> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
        evaluationSum += calculateEvaluation->getEvaluation(*it);
    }
}

TEMPLATE
Chromosome<TIPO> Population<TIPO>::roulette()
{
    updateEvaluationSum();
    default_random_engine generator(time(0));
    double aux = 0;
    double limit = Utility::fRand(0,this->evaluationSum);
    list<Chromosome<int> >::iterator it;
    for(it = chromosomes.begin() && (aux < limit); it != chromosomes.end(); it++){
        aux += it->getEvaluation();
    }
    it--;
    return *it;
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

TEMPLATE
void Population<TIPO>::updateEvaluationSum() /*Calcula o valor de todos os cromossomos*/
{
    this->evaluationSum = 0;
    for(list<Chromosome<int> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
        it->setEvaluation(this->calculateEvaluation->getEvaluation(*it));
        this->evaluationSum += it->getEvaluation();
    }
}
