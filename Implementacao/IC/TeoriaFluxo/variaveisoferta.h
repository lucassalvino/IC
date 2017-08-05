#ifndef VARIAVEISOFERTA_H
#define VARIAVEISOFERTA_H


class VariaveisOferta
{
private:
    float *V_;  //V*
    float *V_l; //Vl
    float *Vf; //Vf
public:
    VariaveisOferta();
    float capacidade(float __hmin);
    float capacidadeIdeal();
    float fluxoSaturacao(float __hs);
    float VFL();
};

#endif // VARIAVEISOFERTA_H
