#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
namespace  BaseGraph {
class Vertex
{
public:
    Vertex();
    Vertex(int id);
    void setId(int value);
    int getId();
    int numberAdjacents();
    int getAdjacentAt(int index);
    void addVertexAdjacent(int idVertice);
private:
    int ID;
    std::vector<int> adjacent;
protected:
};
}
#endif // VERTEX_H
