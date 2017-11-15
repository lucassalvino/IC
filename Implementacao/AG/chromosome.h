#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <iostream>
#include <stdio.h>
#include "generategene.h"
#include <vector>
using namespace std;
#define TEMPLATE template<class TIPO>

TEMPLATE
class Chromosome
{
public:
    Chromosome(){
        numberOfElements = -1;
        evaluation = 0;
        idGene = -1;
    }

    ~Chromosome(){
        clear();
    }

    virtual vector<TIPO> getGene(){
        return gene;
    }

    virtual TIPO getGeneAt(int index) const
    {
        if(index < 0 || index >= this->numberOfElements)
            throw string("[index] he invalido, ou variaveis cromossomo nao inicializado");
        return gene[index];
    }
    virtual void setGeneAt(int index, TIPO value)
    {
        if(numberOfElements == -1) throw string("He necessário setar a quantidade de genes antes de realizar a inserção de genes");
        if(index < 0 || index >= this->numberOfElements)
            throw string("[index] he invalido ou as variaveis cromossomo nao inicializado");
        this->gene[index] = value; //aki o
    }

    virtual void setGene(vector<TIPO> value)
    {
        if(value.size() == 0)
            throw string("O valor do cromossomo he inválido.");
        else{
            this->gene = value;
            numberOfElements = gene.size();
        }
    }

    virtual void generateRandom(GenerateGene<TIPO> * getGene,int numberOfElements)
    {
        clear();
        this->setNumberOfElements(numberOfElements);
        for(int i = 0; i<numberOfElements;i++)
        {
            this->setGeneAt(i,getGene->getRandomGene());
        }
    }

    Chromosome<TIPO> getSubChromosome(int init,int final){
        if(init < 0 || final < 0 || init > numberOfElements || final > numberOfElements ||  init > final)
            throw string("Os valores [Init] e [Final] sao invalidos");
        Chromosome<TIPO> ret;
        ret.setNumberOfElements(final-init+1);
        int _init = init;
        for(;init<final;init++)
            ret.setGeneAt(init - _init, this->getGeneAt(init));
        return ret;
    }

    int getNumberOfElements()
    {
        return this->numberOfElements;
    }

    void setNumberOfElements(int value){
        if(gene.size() == 0){
            if(value <= 0)throw string ("O tamanho do cromossomo deve ser maior do que 0 [ZERO]");
            clear();
            numberOfElements = value;
            gene.resize(numberOfElements);
        }else{
            throw string("O gene ja foi iniciado, sera necessario apagar o mesmo [clear()], ou criar um novo\n");
        }
    }

    void clear(){
        gene.clear();
        numberOfElements = -1;
        evaluation = 0;
    }

    double getEvaluation(){
        return evaluation;
    }

    void setEvaluation(double value){
        evaluation = value;
    }

    int getIdGene(){
        return idGene;
    }
    void setIdGene(int value){
        idGene = value;
    }
    void swap(int i,int j){
        TIPO aux = getGeneAt(i);
        setGeneAt(i,getGeneAt(j));
        setGeneAt(j,aux);
    }

private:
    mutable vector<TIPO> gene; /*Conjunto de genes*/
    mutable int idGene;
    mutable double evaluation;
    mutable int numberOfElements; /*Numero de elementos do gene*/
};
#endif // CHROMOSOME_H
