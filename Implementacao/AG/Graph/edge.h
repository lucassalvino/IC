#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <utility>
#include "vertex.h"
namespace  BaseGraph {
class Edge
{
public:
    Edge();
    void setOrigin(Vertex* value);
    void setDestiny(Vertex* value);
    void setDistance(double value);
    Vertex* getOrigin() const;
    Vertex* getDestiny() const;
    double getDistance() const;
    std::pair<int,int> getOriginDestiny();

    bool operator< (const Edge& e) const{ /*implementado para comparacoes na set*/
        if(origin && destiny){
            if(this->origin->getId() == e.getOrigin()->getId() && this->destiny->getId() == e.destiny->getId())return false;
            return true;
        }
        else {
            throw std::string("nao e possivel utilizar uma aresta que nao esteja inicializada");
        }
    }
protected:
    Vertex* origin;
    Vertex* destiny;
    double distance;
};
}
#endif // EDGE_H
