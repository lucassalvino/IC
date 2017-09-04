#include "testes.h"
int main()
{
    if(Testes::testesBasicos()){
        printf("[OK] Testes Basicos");
    }else{
        printf("[FAIL] Para Testes Básicos");
    }
    printf("\n\n...bye...\n\n");
    return 0;
}
