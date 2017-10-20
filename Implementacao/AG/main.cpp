#include <iostream>
#include <stdio.h>
using namespace std;
#include <random>
#include <time.h>
#include "population.hpp"
#include "calculateevaluation.h"
#include "operators.hpp"
#include "environment.h"
#include "managergeneticalgorithm.h"
#define FATOR 0.00004768372718899898

class XCalculateEvaluation : public CalculateEvaluation<int>{
    virtual double calculateEvaluation(Chromosome<int> value,int init, int final) override {
        return calculateEvaluation(value.getSubChromosome(init,final));
    }

    virtual double calculateEvaluation(Chromosome<int> value) override {
        double ret = 0;
        for(int i = 0; i < value.getNumberOfElements(); i++){
            ret*=2;
            if(value.getGeneAt(i) == 1) ret+=1;
        }
        return ret;
    }
    virtual double getEvaluation(Chromosome<int>* value) override{
        double x = calculateEvaluation(*value,0,21);
        double y = calculateEvaluation(*value,22,44);
        x=x*FATOR-100;
        y=y*FATOR-100;
        value->setEvaluation(1.0/((x*x+y*y)+1.0));
        return value->getEvaluation();
    }
};

class XGenerateGene : public GenerateGene<int>{
public:
    int getRandomGene() override{
        default_random_engine generator;
        generator.seed(rand()/3.141525);
        exponential_distribution<double> distribution(1);
        if(distribution(generator) < 0.5)
            return 1;
        else
            return 0;
    }
};


int main()
{
    ManagerGeneticAlgorithm<int> run;
    Environment ambiente;
    ambiente.setRateChange(0.01);
    run.runGeneticAlgorithm(new XGenerateGene(),new XCalculateEvaluation(), new Operators<int>(),ambiente,60,100,44);
    printf("\n\n...xau...\n\n");
    return 0;
}
