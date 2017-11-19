#include <iostream>
#include <stdio.h>
#include <random>
#include <time.h>
#include <stdlib.h>
#include "Graph/graph.h"
#include <time.h>
#include "ArtigoIIJCECEC/artigoiijcecec.h"
int main()
{
    try{
        srand(time(0));
        executaAG();
    }
    catch (string erro){
        printf("[ERRO]Exectando Main: [%s]\n", erro.c_str());
    }
    return 0;
}
