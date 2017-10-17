#include "operators.h"

TEMPLATE
Chromosome<TIPO> Operators::CrossOverOnePoint(Chromosome<TIPO> mother, Chromosome<TIPO> father)
{
    srand(time(0));
    return CrossOverOnePoint(mother,father,rand() % mother.getNumberOfElements());
}

TEMPLATE
Chromosome<TIPO> Operators::CrossOverOnePoint(Chromosome<TIPO> mother, Chromosome<TIPO> father, int divisionPoint)
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
Chromosome<TIPO> Operators::CrossOverTwoPoint(Chromosome<TIPO> mother, Chromosome<TIPO> father)
{
    srand(time(0));
    int first, second;
    generateTwoDivisionPoints(first,second,mother.getNumberOfElements());
    CrossOverTwoPoint(mother,father,first,second);
}

TEMPLATE
Chromosome<TIPO> Operators::CrossOverTwoPoint(Chromosome<TIPO> mother, Chromosome<TIPO> father, int firstDivisionPoint, int secondDivisionPoint)
{
    if(mother.getNumberOfElements() != father.getNumberOfElements()) throw string("[ERROR] O numero de genes da mae deve ser igual ao numero de genes do pai");
    if(firstDivisionPoint < 0 || firstDivisionPoint > mother.getNumberOfElements() || secondDivisionPoint < 0 || secondDivisionPoint > mother.getNumberOfElements()) throw string("[ERROR] O Ponto de Divisão não deve ser negativo ou maior que a quantidade de genes dos pais");
    if(firstDivisionPoint > secondDivisionPoint) throw string("[ERROR] O primeiro ponto de Divisão deve ser menor ou igual ao segundo ponto de Divisao");
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
Chromosome<TIPO> Operators::Mutation(Chromosome<TIPO> chromos, double chance, GenerateGene<TIPO> *generateGene)
{
    if(chance < 0 || chance > 1) throw string ("A chance he uma porcentagem, deve estar entre 0 (0%) e 1 (100%).");
    Chromosome<TIPO> ret;
    ret.setNumberOfElements(chromos.getNumberOfElements());
    for(int i=0;i<chromos.getNumberOfElements();i++){
        if(Utility::fRand(0,1) < chance){
            ret.setGeneAt(i,generateGene->getRandomGene());
        }else{
            ret.setGeneAt(i,chromos.getGeneAt(i));
        }
    }
    return ret;
}

TEMPLATE
Operators::generateTwoDivisionPoints(int &firstDivisionPoint, int &secondDivisionPoint, int maxPoint)
{
    firstDivisionPoint = rand()%maxPoint;
    secondDivisionPoint = firstDivisionPoint + (rand()%(maxPoint - firstDivisionPoint));
}
