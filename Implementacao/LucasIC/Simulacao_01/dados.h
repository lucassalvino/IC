#ifndef DADOS_H
#define DADOS_H

#include <assert.h>
#include <iostream>

using namespace std;

/*Classe representa o mapa onde ocorrerá o jogo.
Utiliza-se de uma matriz de ordem NxM para executar o jogo*/

class Dados{
public:
    ~Dados(){
        delete __dados;
    }

    static float getTempoMedio(){
        verificaInstancia();
        return __dados->tempoMedio;
    }

    static void setTempoMedio(float value){
        verificaInstancia();
        __dados->tempoMedio = value;
    }

    static float getTaxaGeracao(){
        verificaInstancia();
        return __dados->taxaGeracao;
    }

    static void setTaxaGeracao(float value){
        verificaInstancia();
        __dados->taxaGeracao = value;
    }

    static void verificaInstancia(){
        if(__dados == 0)
            __dados = new Dados();
    }

private:
    float tempoMedio; //tempo medio
    float taxaGeracao; //taxa media de geracao de entrada
    static Dados * __dados;//pode existir somente

    Dados(){
        tempoMedio = 0;
        taxaGeracao = 0;
    }
};
#endif // DADOS_H

