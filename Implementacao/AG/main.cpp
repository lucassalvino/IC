#include <iostream>
#include <stdio.h>
#include <random>
#include <time.h>
#include "population.hpp"
#include "calculateevaluation.h"
#include "operators.hpp"
#include "environment.h"
#include "managergeneticalgorithm.h"
#include "Graph/graph.h"
#include <time.h>
#define FATOR 0.00004768372718899898
using namespace BaseGraph;
using namespace std;
Graph graf;
int numeroVerticeDestino = 0;

class XCalculateEvaluation : public CalculateEvaluation<int>{
    virtual double calculateEvaluation(Chromosome<int> value,int init, int final) override {
        return calculateEvaluation(value.getSubChromosome(init,final));
    }

    virtual double calculateEvaluation(Chromosome<int> value) override {
        return 0;
    }
    virtual double getEvaluation(Chromosome<int>* value) override{
        int numVertex = 0;
        for(int i = 0,noAtual = 0; i < value->getNumberOfElements() - 1; i++){
            Edge* ver = graf.getEdge(value->getGeneAt(noAtual), value->getGeneAt(noAtual+1));
            if (ver!=0){
                numVertex ++;
                if(value->getGeneAt(noAtual+1) == numeroVerticeDestino){
                    numVertex = graf.getNumVertex();
                }
            }
            else break;
        }
        value->setEvaluation(numVertex / graf.getNumVertex());
        return value->getEvaluation();
    }
};

class XGenerateGene : public GenerateGene<int>{
public:
    int getRandomGene() override{
        return random()%graf.getNumVertex();
    }
};


void criaGrafo(Graph& graf){
    graf.addEdge(0,1,1);
    graf.addEdge(1,2,1);
    graf.addEdge(0,3,1);
    graf.addEdge(3,4,1);
    graf.addEdge(4,2,1);
}

int main()
{
    try{
    srand(time(0));
    criaGrafo(graf);
    printf ("Digite o valor ");
    ManagerGeneticAlgorithm<int> run;
    Environment ambiente;
    ambiente.setRateChange(0.01);
    run.setSaveLog(false);
    run.runGeneticAlgorithm(new XGenerateGene(),new XCalculateEvaluation(), new Operators<int>(),ambiente,100,100,graf.getNumVertex());
    printf("\n\n...xau...\n\n");
    }
    catch (string erro){
        printf("[ERRO]Exectando Main: [%s]\n", erro.c_str());
    }
    return 0;
}
