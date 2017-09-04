#ifndef VERTICE_H
#define VERTICE_H
#include "UUID/guid.h"

class Vertice
{
public:
    Vertice(){
        id = Guid::newGuid();
    }

    void setID(string value){
        id = value;
    }

    string getID(){
        return id;
    }

    string getDescricao(){
        return descricao;
    }

    void setDescricao(string value){
        descricao = value;
    }

private:
    string id;
    string descricao;
};

#endif // VERTICE_H
