#ifndef VARIAVEISDEMANDA_H
#define VARIAVEISDEMANDA_H

//+-+-+-+-+-+-+-+-+-+-+-+-+
//|l|u|c|a|s|s|a|l|v|i|n|o|
//+-+-+-+-+-+-+-+-+-+-+-+-+
/*
Artefatos utilizados para determinar aspectos de demanda para utilização de determinado recurso.
*/
class VariaveisDemanda
{
public:
    static float volumeTrafego(int Nt, float h);
    /*Volume de trafego é dado em segundos
    Nt -> numero de solicitacoes do recurso
    h -> tempo em horas que foi realizada a observação */

    static float taxaPassagem(int Nt,float t);
    /* Taxa de passagem é a relação entre a quantidade de solicitações/tempo para concluir as passagens
     Nt -> Numero de solicitacoes
     t -> tempo em horas de observação.
    */

    static int getTamanhoFila(int n0,float Q, float q,float t);
    /* Determina o tamanho de uma fila
     n0 -> Tamanho inicial da fila
     Q -> Fluxo de demanda
     q -> Fluxo Observado
     t -> Tempo de observacao
    */
};

#endif // VARIAVEISDEMANDA_H
