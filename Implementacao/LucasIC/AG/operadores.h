#ifndef OPERADORES_H
#define OPERADORES_H
/*
 * Operadores genéticos
*/

#include <stdlib.h>
#include <stdio.h>
#include "cromossomo.h"

TEMPLATE_GENE
class Operadores
{
public:
    Cromossomo<TIPO> crossover(Cromossomo<TIPO> pai,Cromossomo<TIPO> mae){
        return crossover(pai,mae,rand()%pai.getNumGenes());
    }

    Cromossomo<TIPO> crossover(Cromossomo<TIPO> pai,Cromossomo<TIPO> mae,int pontoCorte){//ponto de corte
        Cromossomo<TIPO> reto;
        int i=0;
        for(;i<pontoCorte;i++){//copia genes do pai
            reto.InserirElementoAoFinal(pai.getElementoPosicao(i));
        }
        for(;i<mae.getNumGenes();i++){//copia genes da mae
            reto.InserirElementoAoFinal(mae.getElementoPosicao(i));
        }
        return reto;
    }

    Cromossomo<TIPO> multacao(Cromossomo<TIPO> multa){
        int i = rand()%(multa.getNumGenes()/2);
        int j = rand()%(multa.getNumGenes());
        Cromossomo<TIPO>aux = multa.getElementoPosicao(i);
        multa.setElemento(multa.getElementoPosicao(j),i);
        multa.setElemento(aux,j);
        return multa;
    }
};

#endif // OPERADORES_H
