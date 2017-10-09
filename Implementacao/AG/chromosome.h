#ifndef CHROMOSOME_H
#define CHROMOSOME_H
#include <iostream>
#include <stdio.h>
using namespace std;
template <class TIPO>
class Chromosome
{
public:
    virtual Chromosome(){
        gene = 0;
        numberOfElements = 0;
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
    virtual setGeneAt(int index, TIPO value)
    {
        if(index < 0 || index >= this->numberOfElements)
            throw string("[index] he invalido, ou variaveis cromossomo nao inicializado");
        this->gene[index] = value;
    }

    virtual setGene(TIPO* value)
    {
        if(value == 0)
            throw string("O valor do cromossomo he inválido.");
        else
            this->gene = value;
    }

    virtual void generateRandom(TIPO (*generateGene)(),int numberOfElements)
    {
        this->numberOfElements = numberOfElements;
        if(gene == 0)
        {
            gene = new TIPO[this->numberOfElements];
        }
        else
        {
            delete [] gene;
        }
        for(int i = 0; i<numberOfElements;i++)
        {
            gene[i] = generateGene();
        }
    }

    int getNumberOfElements()
    {
        return this->numberOfElements;
    }
private:
    TIPO* gene; /*Conjunto de genes*/
    int numberOfElements; /*Numero de elementos do gene*/
};
#endif // CHROMOSOME_H
