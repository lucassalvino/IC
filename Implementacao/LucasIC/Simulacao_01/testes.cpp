#include "testes.h"
#include "UUID/guid.h"

bool Testes::testesBasicos(){
    Dados::setTaxaGeracao(5); Dados::setTempoMedio(6);
    if(Dados::getTaxaGeracao() != 5 || Dados::getTempoMedio() != 6)return false;
    if(Guid::newGuid().size()!=36) return false; //cria nova guid
    return true;
}
