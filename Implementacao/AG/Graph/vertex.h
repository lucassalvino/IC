#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
namespace  BaseGraph {
class Vertex
{
public:
    Vertex();
    Vertex(int id);
    void setId(int value);
    int getId();
private:
    int ID;
protected:
};
}
#endif // VERTEX_H
