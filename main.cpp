#include "parser.h"
#include "dijkstra.h"

int main() {
    Graph* graph = loadGraph("data.txt");

    if(!graph) return 1;

    dijkstra(graph);
    printResults(graph);

    delete graph;
    return 0;
}
