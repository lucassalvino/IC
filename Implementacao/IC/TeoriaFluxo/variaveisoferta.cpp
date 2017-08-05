#include "variaveisoferta.h"

VariaveisOferta::VariaveisOferta()
{

}

float VariaveisOferta::capacidade(float __hmin)
{
    return (1/__hmin);
}

float VariaveisOferta::fluxoSaturacao(float __hs)
{
    return (1/__hs);
}
