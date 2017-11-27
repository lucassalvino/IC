#ifndef ARTIGOIIJCECEC_H
#define ARTIGOIIJCECEC_H
#include "Graph/graph.h"//class grafo   https://github.com/lucassalvino/myLibraries/tree/master/Graph
#include "environment.h" // Ambiente
#include "chromosome.h"
#include "managergeneticalgorithm.h"
#include "population.hpp"
#include <iostream>
#include <stdio.h>
#include <random>
#include <time.h>
#include <stdlib.h>
using namespace BaseGraph;
using namespace std;

Graph grafo;
int numeroVerticeDestino = 8;
int numeroVerticeOrigem = 0;

void  carregaGrafo(){/*funcao carrega o grafo*/
    grafo.addEdge(0,1,1);
    grafo.addEdge(0,2,3);
    grafo.addEdge(0,3,2);
    grafo.addEdge(1,4,9);
    grafo.addEdge(2,5,5);
    grafo.addEdge(3,6,6);
    grafo.addEdge(4,5,2);
    grafo.addEdge(4,8,7);
    grafo.addEdge(6,8,10);
    grafo.addEdge(5,7,3);
    grafo.addEdge(7,8,2.5);
}
class XGenerateRandomChromosome : public GenerateRandomChromosome<int>{ /*Gera Cromossomo com resposta válida para o grafo*/
public:
    Chromosome<int> GenerateChromosome(int numGenes, int ID) override{
        Chromosome<int> ret ;
        ret.setIdGene(ID);
        ret.setNumberOfElements(numGenes);
        for(int i = 0; i < numGenes; i++){
            ret.setGeneAt(i,-1);//inicializa todos com -1//verticve invalido
        }
        ret.setGeneAt(0,numeroVerticeOrigem);//gerar grafos partir da origem
        int verticeAtual = numeroVerticeOrigem;
        for (int i = 1; i<numGenes; i++){
            vector<int> adjacentes = grafo.getVertex(verticeAtual)->getIDVertexAdjacent(); //todos os nos adjacentes ao no atual
            if((int)adjacentes.size() == 0) return ret;
            int escolha = adjacentes[rand()%(int)adjacentes.size()]; // id do vertice escolhoido
            ret.setGeneAt(i,escolha);
            verticeAtual = escolha;
        }
        return ret;
    }
};

class XRandomGenerateRandomChromosome : public GenerateRandomChromosome<int>{ /*Gera Cromossomo com resposta válida para o grafo*/
public:
    Chromosome<int> GenerateChromosome(int numGenes, int ID) override{
        Chromosome<int> ret ;
        ret.setIdGene(ID);
        ret.setNumberOfElements(numGenes);
        for (int i = 0; i<numGenes; i++){
            ret.setGeneAt(i,rand()%grafo.getNumVertex());
        }
        return ret;

    }
};

class XCalculateEvaluation : public CalculateEvaluation<int>{
    virtual double calculateEvaluation(Chromosome<int> value,int init, int final) override {
        value = value;
        init = init;
        final = final;
        return 0;
    }

    virtual double calculateEvaluation(Chromosome<int> value) override {
        value = value;
        return 0;
    }

    virtual double getEvaluation(Chromosome<int>* value) override{
        double peso = 0;
        bool comeco = false;
        if(value->getGeneAt(0) == numeroVerticeOrigem){
            comeco = true;
            peso += 10; //bonus para o cromossomo. Pois o mesmo possui inicio no local de destino esperado
        }
        for(int i = 0; i < (value->getNumberOfElements() - 1) ; i++){
            if(value->getGeneAt(i+1) == -1)break; //fim do caminho valido para o cromossomo
            Edge* ares = grafo.getEdge(value->getGeneAt(i), value->getGeneAt(i+1));
            if (ares == 0){ // cromossomo com camimnho invalido
                peso -= 5; //penalidade por possuir um caminho inválido
                break;
            }else{
                if(comeco && (value->getGeneAt(i+1) == numeroVerticeDestino)){ // o cromossomo em questao atende os requisitos de origem e destino
                    peso += 20; // este cromossomo atende o percurso origem destino
                }
                peso += ares->getDistance();
            }
        }
        value->setEvaluation(peso);
        return peso;
    }
};

class XGenerateGene : public GenerateGene<int>{
public:
    int getRandomGene() override{
        return rand()%grafo.getNumVertex();
    }
};


void executaAG(){
    carregaGrafo();
    ManagerGeneticAlgorithm<int> run;
    Environment ambiente;
    ambiente.setRateChange(0.01);
    run.setSaveLog(false);
    run.runGeneticAlgorithm(new XGenerateGene(),new XCalculateEvaluation(),ambiente,new XGenerateRandomChromosome(),200,20,6);
}
#endif // ARTIGOIIJCECEC_H
