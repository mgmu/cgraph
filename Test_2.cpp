#include <iostream>
#include "Vertex.hpp"
#include "Edge.hpp"
#include "GarbageCollector.hpp"

using namespace std;

int main() {

	cout << "\nTEST 2 : EDGE\n";
	cout << "Tests creation of edges...\n\n";

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

	cout << "Created vertices :\n";
	cout << *v2 << " " << *v5 << " " << *v8 << " " << *v7 << "\n";
	cout << "\n";

	cout << "Created edges :\n";
	cout << *e1 << " " << *e2 << "\n";
	cout << "\n";

	return EXIT_SUCCESS;
}
