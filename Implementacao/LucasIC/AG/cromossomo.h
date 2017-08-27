#ifndef CROMOSSOMO_H
#define CROMOSSOMO_H
#include <vector>
using namespace std;
#define TEMPLATE_GENE template <class TIPO>

TEMPLATE_GENE
class Cromossomo
{
public:
    TIPO getElementoPosicao(int i){
        if(i>=0&&i<getNumGenes())return _crom[i];
    }

    void InserirElementoAoFinal(TIPO value){
        _crom.push_back(value);
    }

    void setCromossomos(TIPO* cromo){
        _crom.clear();
        int n = (int)sizeof(cromo)/(int)sizeof(TIPO);
        for(int i=0;i<n;i++){
            _crom.push_back(cromo[i]);
        }
    }

    TIPO* getVetCromossomo(){//retorna uma copia dos genes atuais no cromossomo
        TIPO * reto = new TIPO[getNumGenes()];
        for(i=0;i<getNumGenes();i++){
            reto[i] = _crom[i];
        }
        return reto;
    }
    int getNumGenes(){return _crom.size();}
private:
    vector<TIPO> _crom;
};

#endif // CROMOSSOMO_H
