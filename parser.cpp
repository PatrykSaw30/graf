#include "parser.h"
#include <fstream>
#include <iostream>

Graph* loadGraph(const string& filename) {
    ifstream file(filename);

    if(!file) {
        cout << "Error opening file\n";
        return nullptr;
    }

    int n, start;
    file >> n >> start;
    file.ignore();

    Graph* graph = new Graph();
    graph->startIndex = start;

    for(int i = 0; i < n; i++) {
        string name;
        getline(file, name);
        graph->vertices.push_back(new Vertex(name));
    }

    int from, to, cost;
    while(file >> from >> to >> cost) {
        graph->vertices[from]->edges.push_back(Edge(graph->vertices[to], cost));
    }

    return graph;
}
