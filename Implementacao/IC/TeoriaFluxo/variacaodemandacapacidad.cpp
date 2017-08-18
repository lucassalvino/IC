#include "variacaodemandacapacidad.h"

float VariacaoDemandaCapacidad::getFatoresEquivalenciaEspecificos(float o1,float o0)
{
    /*
     * 01/00
    */
    return o1/o0;
}

float VariacaoDemandaCapacidad::getEquivalenciaMedioGloabal(float sumP0)
{
    /*Favor olhar a pagina 12 da apostila em questão*/
    return 1/sumP0;
}
