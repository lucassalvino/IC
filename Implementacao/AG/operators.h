#ifndef OPERATORS_H
#define OPERATORS_H
#include "chromosome.h"
#include "generategene.h"
#include "utility.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "chromossomeoperators.h"

TEMPLATE
class Operators
{
public:
    static Chromosome<TIPO> CrossOverOnePoint(Chromosome<TIPO> mother,Chromosome<TIPO> father);
    static Chromosome<TIPO> CrossOverOnePoint(Chromosome<TIPO> mother,Chromosome<TIPO> father, int divisionPoint);
    static Chromosome<TIPO> CrossOverTwoPoint(Chromosome<TIPO> mother,Chromosome<TIPO> father);
    static Chromosome<TIPO> CrossOverTwoPoint(Chromosome<TIPO> mother,Chromosome<TIPO> father, int firstDivisionPoint, int secondDivisionPoint);
    static Chromosome<TIPO> Mutation(Chromosome<TIPO> chromos);
private:
    static void generateTwoDivisionPoints(int& firstDivisionPoint, int& secondDivisionPoint,int maxPoint);
};

#endif // OPERATORS_H
