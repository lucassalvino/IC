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
    Edge *getEdge(int origin, int destiny);
    Edge *getEdge(Vertex origin, Vertex destiny);
    Edge *getEdge(int index);
    int getIDVertex(int value);
    int getIDVertexIndex(int index);
    int getNumEdge();
    int getNumVertex();
    double **getMatrix();
protected:
    std::vector<int> vertex;
    std::vector<Edge> edges;
    void addEdge(Edge value);
    void addEdge(Vertex *origin, Vertex *destiny, double distance);
private:
    void addVertex(int id);
    Vertex* getVertex(int id);
};
}
#endif // GRAPH_H
