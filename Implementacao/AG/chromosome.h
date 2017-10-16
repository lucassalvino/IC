#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <iostream>
#include <stdio.h>
#include "generategene.h"

using namespace std;
#define TEMPLATE template<class TIPO>

TEMPLATE
class Chromosome
{
public:
    Chromosome(){
        gene = 0;
        numberOfElements = 0;
    }

    ~Chromosome(){
        //clear();
    }

    virtual TIPO* getGene(){
        return gene;
    }

    virtual TIPO getGeneAt(int index)
    {
        if(index < 0 || index >= this->numberOfElements)
            throw string("[index] he invalido, ou variaveis cromossomo nao inicializado");
        return gene[index];
    }
    virtual void setGeneAt(int index, TIPO value)
    {
        if(index < 0 || index >= this->numberOfElements)
            throw string("[index] he invalido, ou variaveis cromossomo nao inicializado");
        this->gene[index] = value;
    }

    virtual void setGene(TIPO* value)
    {
        if(value == 0)
            throw string("O valor do cromossomo he inválido.");
        else
            this->gene = value;
    }

    virtual void generateRandom(GenerateGene<TIPO> * getGene,int numberOfElements)
    {
        this->numberOfElements = numberOfElements;
        if(gene == 0)
        {
            gene = new TIPO[this->numberOfElements];
        }
        else
        {
            delete [] gene;
            gene = new TIPO[this->numberOfElements];
        }
        for(int i = 0; i<numberOfElements;i++)
        {
            gene[i] = getGene->getRandomGene();
        }
    }

    int getNumberOfElements()
    {
        return this->numberOfElements;
    }

    void setNumberOfElements(int value){
        if(gene == 0){
            if(value <= 0)throw string ("O tamanho do cromossomo deve ser maior do que 0 [ZERO]");
            numberOfElements = value;
            gene = new TIPO[this->numberOfElements];
        }else{
            throw string("O gene ja foi iniciado, sera necessario apagar o mesmo [clear()], ou criar um novo\n");
        }
    }

    void clear(){
        if(gene != 0){
            delete [] gene;
        }
        gene = 0;
        numberOfElements = 0;
    }
private:
    TIPO* gene; /*Conjunto de genes*/
    int numberOfElements; /*Numero de elementos do gene*/
};
#endif // CHROMOSOME_H