#include "population.h"

TEMPLATE
Population<TIPO>::Population(GenerateGene<TIPO> *ge, CalculateEvaluation<TIPO>*calc, Operators<TIPO> *operato)
{
    getGene = ge;
    calculateEvaluation = calc;
    operators = operato;
    idGeneration = -1;
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
    for(typename list<Chromosome<TIPO> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
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
    typename list<Chromosome<TIPO> >::iterator it;
    for(it = chromosomes.begin(); (aux < limit) && it != chromosomes.end(); it++){
        aux += it->getEvaluation();
    }
    it--;
    return *it;
}

TEMPLATE
Chromosome<TIPO> Population<TIPO>::getBestChromosome()
{
    Chromosome<TIPO> ret;
    double bestEvaluation = 0;
    for(typename list<Chromosome<TIPO> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
        if(it->getEvaluation() > bestEvaluation){
            bestEvaluation = it->getEvaluation();
            ret = *it;
        }
    }
    return ret;
}

TEMPLATE
void Population<TIPO>::initPopulation(int sizePopulation, int numGenes)
{
    for(int i = 0; i<sizePopulation; i++){
        Chromosome<TIPO> add;
        add.generateRandom(this->getGene,numGenes);
        add.setIdGene(i);
        this->chromosomes.push_back(add);
    }
}

TEMPLATE
void Population<TIPO>::printChomosomeOfPopulation()
{
    for(typename list<Chromosome<TIPO> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
        int * gene = it->getGene();
        for(int i=0; i<it->getNumberOfElements(); i++)
            printf("%d ", gene[i]);
        printf("\n");
    }
}

TEMPLATE
double Population<TIPO>::getEvaluationSum()
{
    return evaluationSum;
}

TEMPLATE
int Population<TIPO>::getIdGeneration()
{
    return idGeneration;
}

TEMPLATE
void Population<TIPO>::setIdGeneration(int value)
{
    idGeneration = value;
}

TEMPLATE
void Population<TIPO>::updateEvaluationSum() /*Calcula o valor de todos os cromossomos*/
{
    this->evaluationSum = 0;
    for(typename list<Chromosome<TIPO> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
        it->setEvaluation(this->calculateEvaluation->getEvaluation(*it));
        this->evaluationSum += it->getEvaluation();
    }
}

TEMPLATE
Environment Population<TIPO>::getEnvironment()
{
    return environment;
}

TEMPLATE
void Population<TIPO>::setEnvironment(Environment value)
{
    environment = value;
}


TEMPLATE
void Population<TIPO>::CalculateNextPopulation()
{
    new_chromosomes.clear();
    for(typename list<Chromosome<TIPO> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
        Chromosome<TIPO> son = operators->CrossOverOnePoint(*it,roulette());
        son = operators->Mutation(son,environment.getRateChange(),this->getGene);
        son.setIdGene(this->idGeneration++);
        new_chromosomes.push_back(son);
    }
}

TEMPLATE
void Population<TIPO>::nextPopulation()
{
    if(new_chromosomes.size() <= 0 )throw string("E necessario Calcular a proxima populacao");
    chromosomes.clear();
    for(typename list<Chromosome<TIPO> >::iterator it = new_chromosomes.begin(); it != new_chromosomes.end(); it++){
        chromosomes.push_back(*it);
    }
}
