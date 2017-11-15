#ifndef CUSTOMALGORITHM_H
#define CUSTOMALGORITHM_H
#include "graph.h"
namespace  BaseGraph {
class CustomAlgorithm
{
public:
    CustomAlgorithm(const Graph *pointerGraph);
    CustomAlgorithm();
    virtual void execute();
    void setInstanceGraph(const Graph* pointerGraph);
protected:
    const Graph* graph;
private:
    void checkInstanceGraph();
    double getDistance(int a, int b);
};
}
#endif // CUSTOMALGORITHM_H
