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
        folder = "log/";
    }
    void setFolderLog(string fol){
        this->folder = fol;
    }

    void setSaveLog(bool save){
        this->saveLog = save;
    }

    void runGeneticAlgorithm(GenerateGene<TIPO> *generateGene,CalculateEvaluation<TIPO>*calculateEval, Operators<TIPO>* operators,Environment enviromnent,int numGeneration,int sizePopulation, int numGenes){
        Population<TIPO> popu (generateGene, calculateEval, operators);
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
                save_Log(popu);
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
    string folder;
    bool saveLog;
    int numGeneration;

    void save_Log(Population<TIPO>& popu){
        char aux[10];*aux = 0;
        sprintf(aux,"%d",numGeneration);
        string patch = folder+QDateTime::currentDateTime().toString().toStdString();
                patch+=string("generation_");
                patch+=string(aux);
                patch+=string(".log");
        replace(patch.begin(),patch.end(),':','_');
        replace(patch.begin(),patch.end(),' ','_');
        FILE* arq = fopen(patch.c_str(),"w");
        if(arq == 0){
            throw string("Nao he possivel abrir o arquivo de logs: ["+patch+"].");
        }
        fprintf(arq,"Ambiente:%s\n",popu.getEnvironment().ToString().c_str());
        fprintf(arq,"ID Populacao[%d]\nNumero de elementos da populacao: [%d]\n",popu.getIdGeneration(),popu.getNumChromosomes());
        fprintf(arq,"Somatorio fator de avaliação dos cromossomos: [%lf]\n",popu.getEvaluationSum());
        fprintf(arq,"ID do melhor Cromossomo [%d]\n",popu.getBestChromosome().getIdGene());
        for(int i = 0;i<popu.getNumChromosomes();i++){
            Chromosome<TIPO> g = popu.getChromosomeAt(i);
            fprintf(arq,"[%d]   [%lf]   [",g.getIdGene(),g.getEvaluation());
            for(int j = 0; j<g.getNumberOfElements();j++){
                fprintf(arq," %d ",g.getGeneAt(j));
            }
            fprintf(arq,"]\n");
        }
        fclose(arq);
    }
};

#endif // MANAGERGENETICALGORITHM_H
