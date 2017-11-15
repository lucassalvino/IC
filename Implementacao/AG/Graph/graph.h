#ifndef GRAPH_H
#define GRAPH_H
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <set>
#include <utility>
#include <limits>
namespace  BaseGraph {
class Graph
{
public:
    Graph();
    void addEdge(int origin, int destiny, double distance);
    void clear();
    void loadFromFile(std::string source);
    void saveInFile(std::string source);
    const Edge *getEdge(int origin, int destiny) const;
    const Edge *getEdge(Vertex origin, Vertex destiny) const;
    const Edge *getEdge(int index) const;
    int getIDVertex(int value) const;
    int getIDVertexIndex(int index) const;
    int getNumEdge() const;
    int getNumVertex() const;
    double **getMatrix() const;
protected:
    std::set<int> vertex;
    std::set<Edge> edges;
    void addEdge(Edge value);
    void addEdge(Vertex *origin, Vertex *destiny, double distance);
};
}
#endif // GRAPH_H
