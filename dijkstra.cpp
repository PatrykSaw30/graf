#include "dijkstra.h"
#include <queue>
#include <algorithm>
#include <iostream>

void dijkstra(Graph* graph) {
    auto cmp = [](Vertex *a, Vertex* b) {
        return a->distance > b->distance;
    };
    priority_queue<Vertex*, vector<Vertex*>, decltype(cmp)> pq(cmp);

    Vertex* start = graph->vertices[graph->startIndex];
    start->distance = 0;
    pq.push(start);

    while(!pq.empty()) {
        Vertex* current = pq.top();
        pq.pop();

        for(auto& edge: current->edges) {
            int newDist = current->distance + edge.cost;

            if(newDist < edge.target->distance) {
                edge.target->distance = newDist;
                edge.target->previous = current;
                pq.push(edge.target);
            }
        }
    }
}

vector<string> getPath(Vertex* v) {
    vector<string> path;

    while (v != nullptr) {
        path.push_back(v->name);
        v = v->previous;
    }

    reverse(path.begin(), path.end());
    return path;
}

void printResult(Graph* graph) {
    Vertex* start = graph->vertices[graph->startIndex];

    for (auto v : graph->vertices) {
        cout << start->name << "->" << v->name << ": ";

        auto path = getPath(v);

        for(int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << " - ";
        }

        cout << ", distance:" << v->distance << " km\n";
    }
}
