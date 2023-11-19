#include <iostream>
#include "Vertex.hpp"
#include "GarbageCollector.hpp"

using namespace std;

int main() {

	cout << "\nTEST 1 : VERTEX\n";
	cout << "Tests creation of vertices...\n\n";

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

	cout << "Created vertices :\n";
	cout << *v1 << " " << *v6 << " " << *v3 << " " << *v4 << "\n";
	cout << "\n";

	return EXIT_SUCCESS;
}
