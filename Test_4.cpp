#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "GarbageCollector.hpp"

using namespace std;

int main() {

	cout << "\nTEST 4 : SYMMETRIZE GRAPH\n\n";

	Vertex *v1 {Vertex::ofLabel("1")};
	Vertex *v2 {Vertex::ofLabel("2")};
	Vertex *v3 {Vertex::ofLabel("3")};

	Edge *e1 {Edge::ofVertices(v1, v2, 3)};
	Edge *e2 {Edge::ofVertices(v1, v3, 2)};
	Edge *e3 {Edge::ofVertices(v1, v3, 5)};	
	Edge *e4 {Edge::ofVertices(v2, v3, 4)};
	Edge *e5 {Edge::ofVertices(v3, v2, 4)};

	Graph *g1 {Graph::of({}, {})};

	g1->addEdge(e1);
	g1->addEdge(e2);
	g1->addEdge(e3);
	g1->addEdge(e4);
	g1->addEdge(e5);

	cout << *g1 << "\n\n";

	cout << "Symmetrizing the graph should add 3 edges : \n";
	cout << "    - |3|---2-->|1|\n";
	cout << "    - |3|---5-->|1|\n";
	cout << "    - |2|---3-->|1|\n\n";

	cout << "Symmetrizing graph...\n";
	g1->symmetrize();

	cout << "\nGraph after symmetrizing it\n";
	cout << *g1 << "\n";

	cout << "Symmetrizing again should not do anything : \n";
	g1->symmetrize();
	cout << *g1 << "\n";

	delete g1;

	return EXIT_SUCCESS;
}
