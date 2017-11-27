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
#include <QDateTime>
#include <algorithm>

TEMPLATE
class ManagerGeneticAlgorithm
{
public:
    ManagerGeneticAlgorithm(){
        saveLog = true;
        log = "";
        folder = "log/";
    }
    void setFolderLog(string fol){
        this->folder = fol;
    }

    void setSaveLog(bool save){
        this->saveLog = save;
    }

    void runGeneticAlgorithm(GenerateGene<TIPO> *generateGene,CalculateEvaluation<TIPO>*calculateEval,Environment enviromnent,GenerateRandomChromosome<TIPO>* generateRandomChormossome,int numGeneration,int sizePopulation, int numGenes, Operators<TIPO>* operators = new Operators<TIPO>()){
        Population<TIPO> popu (generateGene, calculateEval, operators, generateRandomChormossome);
        popu.setEnvironment(enviromnent);
        int i = 0;
        popu.setIdGeneration(i);
        popu.initPopulation(sizePopulation,numGenes);
        for(;i<numGeneration; i++){
            popu.CalculateNextPopulation();
            this->numGeneration = i;
            Generation<TIPO> generation;
            generation.setIdGeneration(i);
            generation.setEvaluationSum(popu.getEvaluationSum());
            generation.setBest(popu.getBestChromosome());
            generations.push_back(generation);
            if(saveLog)
                add_Log(popu);
            popu.nextPopulation();
        }
        /*resumo AG*/
        i=0;
        for(typename list<Generation<TIPO> >::iterator it = generations.begin(); it!= generations.end();i++,it++){
            printf("[LOG] Geracao [%d], melhor resultado [%lf] do cromossomo [%d]. Somatorio geracao: [%lf]\n",i,it->getBest().getEvaluation(),it->getBest().getIdGene(),it->getEvaluationSum());
        }
        if(saveLog) save_Log();
    }

private:
    list<Generation<TIPO> > generations;
    string folder;
    string log;
    bool saveLog;
    int numGeneration;
    void save_Log(){
        string caminho = folder+QDateTime::currentDateTime().toString().toStdString();
        replace(caminho.begin(),caminho.end(),':','_');
        replace(caminho.begin(),caminho.end(),' ','_');
        caminho+=string(".log");
        FILE* arq = fopen(caminho.c_str(),"w");
        if(arq == 0){
            throw string("Nao he possivel abrir o arquivo de logs: ["+caminho+"].");
        }
        fprintf(arq, "%s", log.c_str());
        fclose(arq);
    }

    void add_Log(Population<TIPO>& popu, bool saveLog = false){
        char aux[10];*aux = 0;
        char tmp[50000];*tmp = 0;
        sprintf(aux,"%d",numGeneration);
        string patch = folder+QDateTime::currentDateTime().toString().toStdString();
                patch+=string("generation_");
                patch+=string(aux);
        log += patch + "\n";
        sprintf(tmp,"Ambiente:%s\n",popu.getEnvironment().ToString().c_str()); log += string(tmp);*tmp = 0;
        sprintf(tmp,"ID Populacao[%d]\nNumero de elementos da populacao: [%d]\n",popu.getIdGeneration(),popu.getNumChromosomes());log += string(tmp);*tmp = 0;
        sprintf(tmp,"Somatorio fator de avaliação dos cromossomos: [%lf]\n",popu.getEvaluationSum());log += string(tmp);*tmp = 0;
        sprintf(tmp,"ID do melhor Cromossomo [%d]\n",popu.getBestChromosome().getIdGene());log += string(tmp);*tmp = 0;
        for(int i = 0;i<popu.getNumChromosomes();i++){
            Chromosome<TIPO> g = popu.getChromosomeAt(i);
            sprintf(tmp,"[%d]   [%lf]   [",g.getIdGene(),g.getEvaluation());log += string(tmp);*tmp = 0;
            for(int j = 0; j<g.getNumberOfElements();j++){
                sprintf(tmp," %d ",g.getGeneAt(j));log += string(tmp);*tmp = 0;
            }
            sprintf(tmp,"]\n");log += string(tmp);*tmp = 0;
        }
        if (saveLog)
            save_Log();
    }
};

#endif // MANAGERGENETICALGORITHM_H
