#ifndef CANAL_H
#define CANAL_H

#include "vertice.h"

class Canal
{
public:
    bool getOcupado(){
        return ocupado;
    }

    void setOcupado(bool value){
        ocupado = value;
    }

    Vertice getOrigem(){
        return origem;
    }

    void setOrigem(Vertice value){
        origem = value;
    }

    Vertice getDestino(){
        return destino;
    }

    void setDestino(Vertice value){
        destino = value;
    }

private:
    Vertice origem;
    Vertice destino;
    bool ocupado;
};

#endif // CANAL_H
