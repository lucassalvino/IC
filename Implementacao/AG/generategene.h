#ifndef GENERATEGENE_H
#define GENERATEGENE_H
template <class TIPO>
#include <iostream>
class GenerateGene{
public:
    virtual TIPO getRandomGene(){throw std::string("Função ainda não foi definida");}
private:
};

#endif // GENERATEGENE_H
