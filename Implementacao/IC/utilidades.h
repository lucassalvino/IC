#ifndef UTILIDADES_H
#define UTILIDADES_H


template <class TIPO>
class Utilidades
{
public:
    static TIPO getSumVetor(int n,TIPO * elem,TIPO (*sum)(TIPO,TIPO),TIPO zero){
        TIPO ret = zero;
        for(int i=0;i<n;i++){
            ret = (*sum)(ret,elem[i]);
        }
        return ret;
    }
};

#endif // UTILIDADES_H
