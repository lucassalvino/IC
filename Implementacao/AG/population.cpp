#include "population.h"

TEMPLATE
Population<TIPO>::Population(GenerateGene<TIPO> *ge, CalculateEvaluation<TIPO>*calc, Operators<TIPO> *operato, GenerateRandomChromosome<TIPO> *generateCromossome)
{
    if(ge == 0) throw string("GenerateGene esta nulo");
    if(calc == 0) throw string("CalculateEvaluation esta nulo");
    if(operato == 0) throw string("Operators esta nulo");
    if(generateCromossome == 0) throw string("GenerateRandomChromosome esta nulo");
    getGene = ge;
    calculateEvaluation = calc;
    operators = operato;
    idGeneration = -1;
    getChromossome = generateCromossome;
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
    Chromosome<TIPO>* ret;
    double bestEvaluation = -9000;
    this->updateEvaluationSum();
    for(typename list<Chromosome<TIPO> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
        if(it->getEvaluation() > bestEvaluation){
            bestEvaluation = it->getEvaluation();
            ret = &(*it);
        }
    }
    return *ret;
}

TEMPLATE
void Population<TIPO>::initPopulation(int sizePopulation, int numGenes)
{
    if(getChromossome == 0)throw string ("He necessario setar o gerador de Cromossomos");
    for(int i = 0; i<sizePopulation; i++){
        this->chromosomes.push_back(getChromossome->GenerateChromosome(numGenes));
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
        it->setEvaluation(this->calculateEvaluation->getEvaluation(&(*it)));
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
int Population<TIPO>::getNumChromosomes()
{
    return chromosomes.size();
}

TEMPLATE
Chromosome<TIPO> Population<TIPO>::getChromosomeAt(int index)
{
    typename list<Chromosome<TIPO> >::iterator it = chromosomes.begin();
    if(chromosomes.size() > index && index >= 0)
        for(;index!=0;index--)
            it++;
    return *it;
}


TEMPLATE
void Population<TIPO>::CalculateNextPopulation()
{
    new_chromosomes.clear();
    updateEvaluationSum();
    for(typename list<Chromosome<TIPO> >::iterator it = chromosomes.begin(); it != chromosomes.end(); it++){
        Chromosome<TIPO> son = operators->CrossOverTwoPoint(*it,roulette());
        son.setIdGene(this->idGeneration++);
        son = operators->Mutation(son,environment.getRateChange());
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
    new_chromosomes.clear();
}
