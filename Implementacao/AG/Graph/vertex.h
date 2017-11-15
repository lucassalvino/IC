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
    int getId() const;

    bool operator< (const Vertex& e) const{ /*implementado para comparacoes na set*/
        if(e.getId() != getId())return true;
        return false;
    }
private:
    int ID;
protected:
};
}
#endif // VERTEX_H
