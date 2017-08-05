#ifndef VARIAVEISSERVICO_H
#define VARIAVEISSERVICO_H

//+-+-+-+-+-+-+-+-+-+-+-+-+
//|l|u|c|a|s|s|a|l|v|i|n|o|
//+-+-+-+-+-+-+-+-+-+-+-+-+
/*
Artefatos utilizados para determinar aspectos de demanda para utilização de determinado recurso.
*/
class VariaveisServico
{
public:
    float getVelocidadeGlobal(float dis,float t);
    /* retorna velocidade média dis/t
     * dis-> distancia percorrida
     * t -> tempo gasto
    */
    float getVelocidadePercurso(float dis,float t);
    /* media de distancia percorrida / tempo em movimento
     * dis -> distancia percorrida
     * t -> tempo em movimento definido pela função abaixo getTempoEmMovimento
    */
    float getTempoEmMovimento(float l,float v, float d);
    /* tempo em que realmente o movel permanece em movimento
     * l -> distancia total
     * v -> velocidade do percurso
     * d -> atraso total ou em parada
    */
};

#endif // VARIAVEISSERVICO_H
