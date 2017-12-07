#include "operators.h"

TEMPLATE
Chromosome<TIPO> Operators<TIPO>::CrossOverOnePoint(Chromosome<TIPO> mother, Chromosome<TIPO> father)
{
    srand(time(0));
    return CrossOverOnePoint(mother,father,rand() % mother.getNumberOfElements());
}

TEMPLATE
Chromosome<TIPO> Operators<TIPO>::CrossOverOnePoint(Chromosome<TIPO> mother, Chromosome<TIPO> father, int divisionPoint)
{
    if(mother.getNumberOfElements() != father.getNumberOfElements()) throw string("[ERROR] O numero de genes da mae deve ser igual ao numero de genes do pai");
    if(divisionPoint < 0 || divisionPoint > mother.getNumberOfElements()) throw string("[ERROR] O Ponto de Divisão não deve ser negativo ou maior que a quantidade de genes dos pais");
    Chromosome<TIPO> ret;
    ret.setNumberOfElements(mother.getNumberOfElements());
    int i = 0;
    for (;i<divisionPoint;i++){
        ret.setGeneAt(i,mother.getGeneAt(i));
    }
    for (;i<father.getNumberOfElements();i++){
        ret.setGeneAt(i,father.getGeneAt(i));
    }
    return ret;
}

TEMPLATE
Chromosome<TIPO> Operators<TIPO>::CrossOverTwoPoint(Chromosome<TIPO> mother, Chromosome<TIPO> father)
{
    int first, second;
    generateTwoDivisionPoints(first,second,mother.getNumberOfElements());
    return CrossOverTwoPoint(mother,father,first,second);
}

TEMPLATE
Chromosome<TIPO> Operators<TIPO>::CrossOverTwoPoint(Chromosome<TIPO> mother, Chromosome<TIPO> father, int firstDivisionPoint, int secondDivisionPoint)
{
    if(mother.getNumberOfElements() != father.getNumberOfElements())
        throw string("[ERROR] O numero de genes da mae deve ser igual ao numero de genes do pai");
    if(firstDivisionPoint < 0 || firstDivisionPoint > mother.getNumberOfElements() || secondDivisionPoint < 0 || secondDivisionPoint > mother.getNumberOfElements())
        throw string("[ERROR] O Ponto de Divisão não deve ser negativo ou maior que a quantidade de genes dos pais");
    if(firstDivisionPoint > secondDivisionPoint)
        throw string("[ERROR] O primeiro ponto de Divisão deve ser menor ou igual ao segundo ponto de Divisao");
    int i=0;
    Chromosome<TIPO> ret;
    ret.setNumberOfElements(mother.getNumberOfElements());
    for(;i<firstDivisionPoint;i++){
        ret.setGeneAt(i,mother.getGeneAt(i));
    }
    for(;i<secondDivisionPoint;i++){
        ret.setGeneAt(i,father.getGeneAt(i));
    }
    for(;i<mother.getNumberOfElements();i++){
        ret.setGeneAt(i,mother.getGeneAt(i));
    }
    return ret;
}

TEMPLATE
Chromosome<TIPO> Operators<TIPO>::Mutation(Chromosome<TIPO> chromos)
{
    int n = chromos.getNumberOfElements();
    for(int i=0;i<n;i++){
       chromos.swap(rand()%n,rand()%n);
    }
    return chromos;
}

TEMPLATE
void Operators<TIPO>::generateTwoDivisionPoints(int &firstDivisionPoint, int &secondDivisionPoint, int maxPoint)
{
    firstDivisionPoint = rand()%maxPoint;
    secondDivisionPoint = firstDivisionPoint + (rand()%(maxPoint - firstDivisionPoint));
}
