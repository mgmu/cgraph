#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "GarbageCollector.hpp"

using namespace std;

int main(){

	cout << "\nTEST 5 : KRUSKAL\n\n";

	Vertex *a {Vertex::ofLabel("A")};
	Vertex *b {Vertex::ofLabel("B")};
	Vertex *c {Vertex::ofLabel("C")};
	Vertex *d {Vertex::ofLabel("D")};
	Vertex *e {Vertex::ofLabel("E")};

	Graph *graph {Graph::of({}, {})};

	graph->addEdge(*a, *b, 1);
	graph->addEdge(*a, *c, 4);
	graph->addEdge(*b, *c, 5);
	graph->addEdge(*b, *d, 6);
	graph->addEdge(*b, *e, 3);
	graph->addEdge(*c, *d, 6);
	graph->addEdge(*c, *e, 2);

	cout << *graph << "\n";

	cout << "Applying Kruskal's algorithm on previous graph...\n";
	std::vector<Edge*> *res {graph->kruskal()};

	cout << "Edges of the minimum spanning tree : \n";
	for (size_t i {0}; i < res->size(); i++)
		cout << *((*res)[i]) << "\n";

	delete res;
	delete graph;
}
