#include "variaveisservico.h"

float VariaveisServico::getVelocidadeGlobal(float dis, float t)
{
    return dis/t;
}

float VariaveisServico::getVelocidadePercurso(float dis, float t)
{
    return dis/t;
}

float VariaveisServico::getTempoEmMovimento(float l, float v, float d)
{
    return (l/v)+d;
}
