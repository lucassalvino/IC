#include <iostream>
#include <stdio.h>
#include "utilidades.h"

int soma(int a,int b){return a+b;}
int main(){
    int vet[] = {1,2,3,4,5};
    printf("%d\n",Utilidades<int>::getSumVetor(5,vet,soma,0));
    return 0;
}
