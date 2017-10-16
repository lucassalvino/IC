#include <iostream>
#include <stdio.h>
using namespace std;
#include <random>
#include <time.h>
#include "population.hpp"

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
    Population<int> popu (new XGenerateGene());
    popu.initPopulation(20,10);
    popu.printChomosomeOfPopulation();
    printf("\n\n...xau...\n\n");
    return 0;
}
