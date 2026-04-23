#include <string>
#include <vector>

using namespace std;

class Vertex;

class Edge {
public:
    Vertex* target;
    int cost;

    Edge(Vertex* t, int c);
};

class Vertex {
public:
    string name;
    vector<Edge> edges;
    int distance;
    Vertex* previous;

    Vertex(string n);
};

class Graph {
public: 
    vector<Vertex*> vertices;
    int startIndex;

    ~Graph();
};
