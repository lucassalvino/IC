#include <iostream>
#include <stdio.h>
#include <random>
#include <time.h>
#include <stdlib.h>
#include "population.hpp"
#include "calculateevaluation.h"
#include "operators.hpp"
#include "environment.h"
#include "managergeneticalgorithm.h"
#include "Graph/graph.h"
#include <time.h>
using namespace BaseGraph;
using namespace std;
Graph graf;
int numeroVerticeDestino = 0;
int numeroVerticeOrigem = 0;

class XCalculateEvaluation : public CalculateEvaluation<int>{
    virtual double calculateEvaluation(Chromosome<int> value,int init, int final) override {
        return calculateEvaluation(value.getSubChromosome(init,final));
    }

    virtual double calculateEvaluation(Chromosome<int> value) override {
        return 0;
    }
    virtual double getEvaluation(Chromosome<int>* value) override{
        int numVertex = 0;
        if(value->getGeneAt(0) != numeroVerticeOrigem){
            numVertex = 0;
        }else
            for(int i = 0,noAtual = 0; i < value->getNumberOfElements() - 1; i++){
                Edge* ver = graf.getEdge(value->getGeneAt(noAtual), value->getGeneAt(noAtual+1));
                if (ver!=0){
                    numVertex ++;
                    if(value->getGeneAt(noAtual+1) == numeroVerticeDestino){
                        numVertex = graf.getNumVertex();
                        printf("ENCONTREI O CAMINHO!!!! Cromossomo de ID[%d]: \n",value->getIdGene());
                        for(int j = 0; j<=i+1; j++)
                            printf("[%d] -> ",value->getGeneAt(j));
                        printf("FIM\n\n");
                        exit(0);
                    }
                }
                else{
                    break;
                }
            }
        value->setEvaluation(numVertex / graf.getNumVertex());
        return value->getEvaluation();
    }
};

class XGenerateGene : public GenerateGene<int>{
public:
    int getRandomGene() override{
        return rand()%graf.getNumVertex();
    }
};

class XGenerateRandomChromosome : public GenerateRandomChromosome<int>{
public:
    Chromosome<int> GenerateChromosome(int numGenes, int ID) override{
        Chromosome<int> ret ;
        ret.setIdGene(ID);
        ret.setNumberOfElements(numGenes);
        ret.setGeneAt(0,numeroVerticeOrigem);
        int ultimoGene = numeroVerticeOrigem;
        bool jaAdicionado[graf.getNumVertex()] ={0};
        jaAdicionado[numeroVerticeOrigem] = 1;
        for(int i = 1; i<numGenes; i++){
            int destino;
            for(int j=0; j<graf.getNumVertex();j++){
                destino = rand()%graf.getNumVertex();
                Edge* ten = graf.getEdge(ultimoGene,destino);
                if(ten == 0 && j == graf.getNumVertex() && !jaAdicionado[destino]){
                    printf("[WARNING] Impossivel gerar cromossomo em [%s]",__FUNCTION__);
                    destino = -1;
                    break;
                }
                if(ten != 0 && !jaAdicionado[destino])break;
            }
            ret.setGeneAt(i,destino);
            jaAdicionado[destino] = true;
        }
        return ret;
    }
};

void criaGrafo(Graph& graf){
    graf.addEdge(0,1,1);
    graf.addEdge(1,2,1);
    graf.addEdge(0,3,1);
    graf.addEdge(3,4,1);
    graf.addEdge(4,2,1);
    graf.saveInFile(string("C:/DEMETER/grafo.txt"));
}

int main()
{
    try{
        srand(time(0));
        criaGrafo(graf);
        printf ("Digite o vertice de Origem: "); scanf ("%d", &numeroVerticeOrigem);
        printf ("Digite o vertice de Destino: "); scanf ("%d", &numeroVerticeDestino);
        ManagerGeneticAlgorithm<int> run;
        Environment ambiente;
        ambiente.setRateChange(0.01);
        run.setSaveLog(false);
        run.runGeneticAlgorithm(new XGenerateGene(),new XCalculateEvaluation(), new Operators<int>(),ambiente,new XGenerateRandomChromosome(),100,100,graf.getNumVertex());
        printf("\n\n...xau...\n\n");
    }
    catch (string erro){
        printf("[ERRO]Exectando Main: [%s]\n", erro.c_str());
    }
    return 0;
}
