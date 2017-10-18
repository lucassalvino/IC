#ifndef MANAGERGENETICALGORITHM_H
#define MANAGERGENETICALGORITHM_H
#include <iostream>
#include <stdio.h>
using namespace std;
#include <random>
#include <time.h>
#include "population.hpp"
#include "calculateevaluation.h"
#include "operators.hpp"
#include "environment.h"
#include "generation.h"

TEMPLATE
class ManagerGeneticAlgorithm
{
public:
    void runGeneticAlgorithm(GenerateGene<TIPO> *generateGene,CalculateEvaluation<TIPO>*calculateEval, Operators<TIPO>* operators,Environment enviromnent,int numGeneration,int sizePopulation, int numGenes){
        Population<TIPO> popu (generateGene, calculateEval, operators);
        popu.setEnvironment(enviromnent);
        int i = 0;
        popu.setIdGeneration(i);
        popu.initPopulation(sizePopulation,numGenes);
        for(;i<numGeneration; i++){
            popu.CalculateNextPopulation();

            Generation<TIPO> generation;
            generation.setIdGeneration(i);
            generation.setEvaluationSum(popu.getEvaluationSum());
            generation.setBest(popu.getBestChromosome());
            generations.push_back(generation);

            popu.nextPopulation();
        }

        /*resumo AG*/
        i = 0;
        for(typename list<Generation<TIPO> >::iterator it = generations.begin(); it!= generations.end();i++,it++){
            printf("[LOG] Geracao [%d], melhor resultado [%lf] do cromossomo [%d]. Somatorio geracao: [%lf]\n",i,it->getBest().getEvaluation(),it->getBest().getIdGene(),it->getEvaluationSum());
        }
    }
private:
    list<Generation<TIPO> > generations;
};

#endif // MANAGERGENETICALGORITHM_H
