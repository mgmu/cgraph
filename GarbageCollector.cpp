#include "GarbageCollector.hpp"

GarbageCollector GarbageCollector::instance {};

GarbageCollector::GarbageCollector(): vertices {}, edges {} {
	std::cout << "built garbage collector\n";
}

GarbageCollector* GarbageCollector::getInstance() {
	return &instance;
}

bool GarbageCollector::addVertex(Vertex* const vertex) {
	for (const Vertex* const v : vertices)
		if (v == vertex) return false;
	vertices.push_back(vertex);
	std::cout << "--GARBAGECOLLECTOR: added vertex\n";
	return true;
}

bool GarbageCollector::addEdge(Edge* const edge) {
	for (const Edge* const e : edges)
		if (e == edge) return false;
	edges.push_back(edge);
	std::cout << "--GARBAGECOLLECTOR: added edge\n";
	return true;
}

void GarbageCollector::collectGarbage() {
	for (Vertex *v : vertices) {
		std::cout << "--GARBAGECOLLECTOR: deleting vertex at " << v << "\n";
		delete v;
	}
	for (Edge *e : edges) {
		std::cout << "--GARBAGECOLLECTOR: deleting edge at " << e << "\n";
		delete e;
	}
}

GarbageCollector::~GarbageCollector() {
	collectGarbage();
}
