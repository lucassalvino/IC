#include "vertex.h"

BaseGraph::Vertex::Vertex()
{
    ID = -1;
}

BaseGraph::Vertex::Vertex(int id)
{
    setId(id);
}

void BaseGraph::Vertex::setId(int value)
{
    if(value < 0)throw std::string("O valor ID de um Vertice nao pode ser negativo");
    ID = value;
}

int BaseGraph::Vertex::getId()
{
    return ID;
}


int BaseGraph::Vertex::numberAdjacents()
{
    return adjacent.size();
}

int BaseGraph::Vertex::getAdjacentAt(int index)
{
    if(index < 0 || index >= numberAdjacents())
        throw std::string("index he invalido para getAdjacentAt");
    return adjacent[index];
}

void BaseGraph::Vertex::addVertexAdjacent(int idVertice)
{
    for(int i = 0; i<numberAdjacents(); i++){
        if(idVertice == adjacent[i])return;
    }
    adjacent.push_back(idVertice);
}
