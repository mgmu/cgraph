#include <iostream>
#include <vector>
#include "Graph.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "GarbageCollector.hpp"

using namespace std;

int main() {

	cout << "\nTEST 3 : GRAPH\n\n";

	cout << "Building a graph represented by the following map :  \n";
	cout << "entry [vertex from : (vertex to, weight), ...] where \n";
	cout << "(from, to, weight) is an edge of the graph.\n";
	cout << "1: (2,2), (3,1), (3,4)\n";
	cout << "2: (1,3), (5,2), (4,6), (5,5)\n";
	cout << "3: (4,5)\n";
	cout << "4: (6,8)\n";
	cout << "5: (4,7)\n";
	cout << "6: (7,3)\n";
	cout << "7: \n";
	cout << "8: (7,2)\n\n";

	cout << "Building vertices...\n";
	Vertex *v1 {Vertex::ofLabel("1")};
	cout << "\n";

	Vertex *v6 {Vertex::ofLabel("6")};
	cout << "\n";

	Vertex *v3 {Vertex::ofVertex(v1)};
	cout << "\n";

	Vertex *v4 {Vertex::ofLabel("4")};
	cout << "\n";

	cout << "Current label of " << v3 << " --> " << v3->getLabel() << "\n";
	v3->setLabel("3");
	cout << "New label of " << v3 << " --> " << v3->getLabel() << "\n";
	cout << "\n";

	cout << "\nBuilding edges...\n";
	Edge *e1 {Edge::ofLabels("2", "5", 5)};
	Vertex *v2 {e1->getFrom()};
	Vertex *v5 {e1->getTo()};
	cout << "\n";

	Edge *e2 {Edge::ofEdge(e1)};
	Vertex *v8 {e2->getFrom()};
	Vertex *v7 {e2->getTo()};

	cout << "Current label of " << v8 << " --> " << v8->getLabel() << "\n";
	v8->setLabel("8");
	cout << "New label of " << v8 << " --> " << v8->getLabel() << "\n";
	cout << "Current label of " << v7 << " --> " << v7->getLabel() << "\n";
	v7->setLabel("7");
	cout << "New label of " << v7 << " --> " << v7->getLabel() << "\n";	
	cout << "\n";

	cout << "Edge e3 |1|---2-->|2|\n";
	Edge *e3 {Edge::ofVertices(v1, v2, 2)};
	cout << "\n";

	cout << "Edge e4 |2|---3-->|1|\n";
	Edge *e4 {Edge::ofVertices(v2, v1, 3)};
	cout << "\n";

	cout << "Edge e5 |2|---2-->|5|\n";
	Edge *e5 {Edge::ofVertices(v2, v5, 2)};
	cout << "\n";

	cout << "Edge e6 |1|---1-->|3|\n";
	Edge *e6 {Edge::ofVertices(v1, v3, 1)};
	cout << "\n";

	cout << "Edge e7 |1|---4-->|3|\n";
	Edge *e7 {Edge::ofVertices(v1, v3, 4)};
	cout << "\n";

	cout << "Edge e8 |3|---5-->|4|\n";
	Edge *e8 {Edge::ofVertices(v3, v4, 5)};
	cout << "\n";	

	cout << "Edge e9 |2|---6-->|4|\n";
	Edge *e9 {Edge::ofVertices(v2, v4, 6)};
	cout << "\n";

	cout << "Edge e10 |5|---7-->|4|\n";
	Edge *e10 {Edge::ofVertices(v5, v4, 7)};
	cout << "\n";

	cout << "Edge e11 |4|---8-->|6|\n";
	Edge *e11 {Edge::ofVertices(v4, v6, 8)};
	cout << "\n";

	cout << "Edge e12 |6|---3-->|7|\n";
	Edge *e12 {Edge::ofVertices(v6, v7, 3)};
	cout << "\n";

	vector<Vertex *> vertices {v1, v2, v3, v4, v5, v6, v7, v8};
	vector<Edge *> edges {e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12};

	cout << "\nBuilding graphs...\n";
	cout << "Graph g1\n";
	Graph *g1 {Graph::of(vertices, edges)};
	cout << *g1;
	cout << "Weight of all edges : " << g1->weight() << "\n";
	cout << "\n";

	cout << "Graph g2\n";
	Graph *g2 {Graph::ofGraph(*g1)};
	cout << *g2;
	cout << "\n";

	cout << "Add edge |7|---2-->|8| to connect |8| to graph\n";
	Vertex *v7g2 {g2->getVertexByLabel("7")};
	cout << "Vertex v7 of G2 " << *v7 << "[at " << v7g2 << "]\n";
	Vertex *v8g2 {g2->getVertexByLabel("8")};
	cout << "Vertex v8 of G2 " << *v8 << "[at " << v8g2 << "]\n";
	Edge *e13 {Edge::ofVertices(v7g2, v8g2, 2)};
	g2->addEdge(e13);
	cout << "\n";

	cout << "Final graph [at " << g2 << "]\n";
	cout << *g2;
	cout << "Weight of all edges : " << g2->weight() << "\n";

	delete g1;
	delete g2;

	return EXIT_SUCCESS;
}
