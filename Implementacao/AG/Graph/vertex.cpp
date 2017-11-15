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
