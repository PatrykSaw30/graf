#include "Graph.h"
#include <limits>

Edge::Edge(Vertex* t, int c) : target(t), cost(c) {}

Vertex::Vertex(string n){
    name = n;
    distance = numeric_limits<int>::max();
    previous = nullptr;
}

Graph::~Graph() {
    for (auto v : vertices){
        delete v;
    }
}
