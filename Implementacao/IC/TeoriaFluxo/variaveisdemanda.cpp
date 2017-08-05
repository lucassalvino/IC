#include "variaveisdemanda.h"
/*acreditava que podia ver um mundo diferente <obito>*/

float VariaveisDemanda::volumeTrafego(int Nt, float h){
    return 3600.0/(Nt/h);
}

float VariaveisDemanda::taxaPassagem(int Nt, float t){
    return Nt/t;
}

int VariaveisDemanda::getTamanhoFila(int n0, float Q, float q, float t){
    return n0 + (int)((Q-q)*t);
}
