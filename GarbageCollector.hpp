#ifndef _GARBAGECOLLECTOR
#define _GARBAGECOLLECTOR

#include <iostream>
#include <vector>
#include "Vertex.hpp"
#include "Edge.hpp"

class Vertex;
class Edge;
class Graph;

class GarbageCollector {
private:

	/* The vector of references to creted vertices. */
	std::vector<Vertex*> vertices;

	/* The vector of references to created edges. */
	std::vector<Edge*> edges;

	/* GarbageCollector instance. */
	static GarbageCollector instance;

	/* Constructs a new GarbageCollector. */
	GarbageCollector();

	/* Deletes all the memory allocated to the references stored in this 
	 * garbage collector. */
	void collectGarbage();

public:

	/* Returns a pointer to the GarbageCollector instance. */
	static GarbageCollector* getInstance();

	/* Returns true if it adds the given vertex reference to this garbage
	 * collector. If the reference is already present, it is not added. */
	bool addVertex(Vertex* const vertex);

	/* Returns true if it adds the given edge reference to this garbage
	 * collector. If the reference is already present, it is not added. */
	bool addEdge(Edge* const edge);

	/* GarbageCollector destructor. */
	~GarbageCollector();
};

#endif
