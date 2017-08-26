#ifndef VARIACAODEMANDACAPACIDAD_H
#define VARIACAODEMANDACAPACIDAD_H


//+-+-+-+-+-+-+-+-+-+-+-+-+
//|l|u|c|a|s|s|a|l|v|i|n|o|
//+-+-+-+-+-+-+-+-+-+-+-+-+

class VariacaoDemandaCapacidad
{
public:

    /* favor olhar página 12 da apostila em questão*/
    static float getFatoresEquivalenciaEspecificos(float o1, float o0);
    static float getEquivalenciaMedioGloabal(float sumP0);
    static float getDistribuicaoIntervalosChegadas(float q);

};

#endif // VARIACAODEMANDACAPACIDAD_H
