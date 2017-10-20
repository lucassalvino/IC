#ifndef CHROMOSSOMEOPERATORS_H
#define CHROMOSSOMEOPERATORS_H
#include "chromosome.h"

TEMPLATE
class ChromossomeOperators
{
public:
    static bool equal(Chromosome<TIPO> a,Chromosome<TIPO> b){
        int n = a.getNumberOfElements();
        for(int i = 0; i<n;i++){
            if(a.getGeneAt(i) != b.getGeneAt(i)) return false;
        }
        return true;
    }
    static bool less(Chromosome<TIPO> a,Chromosome<TIPO> b){
        return false;
    }
    static bool larger(Chromosome<TIPO> a,Chromosome<TIPO> b){
        return false;
    }
    static void attribution(Chromosome<TIPO> destiny,Chromosome<TIPO> source){
        destiny = source;
    }
    static void swap(TIPO &a,TIPO &b){
        TIPO c;
        c = a;
        a = b;
        b = c;
    }
};
#endif // CHROMOSSOMEOPERATORS_H
