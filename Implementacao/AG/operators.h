#ifndef OPERATORS_H
#define OPERATORS_H
#include "chromosome.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

TEMPLATE
class Operators
{
public:
    static Chromosome<TIPO> CrossOverOnePoint(Chromosome<TIPO> mother,Chromosome<TIPO> father);
    static Chromosome<TIPO> CrossOverOnePoint(Chromosome<TIPO> mother,Chromosome<TIPO> father, int divisionPoint);
    static Chromosome<TIPO> CrossOverTwoPoint(Chromosome<TIPO> mother,Chromosome<TIPO> father);
    static Chromosome<TIPO> CrossOverTwoPoint(Chromosome<TIPO> mother,Chromosome<TIPO> father, int firstDivisionPoint, int secondDivisionPoint);
private:
    static generateTwoDivisionPoints(int& firstDivisionPoint, int& secondDivisionPoint,int maxPoint);
};

#endif // OPERATORS_H