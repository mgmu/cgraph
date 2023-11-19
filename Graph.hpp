#ifndef _GRAPH
#define _GRAPH

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "Vertex.hpp"
#include "Edge.hpp"
#include "GarbageCollector.hpp"

class Graph {

private:

	/* The vertices of this graph. */
	std::vector<Vertex*> vertices;

	/* The edges of this graph. */
	std::vector<Edge*> edges;

	/* Constructs a new graph which vertices and edges points to the given
	 * vertices and edges. */
	Graph(const std::vector<Vertex*> &otherVertices,
		  const std::vector<Edge*> &otherEdges);

	/* Constructs a new graph which vertices and edges are equal in value
	 * to other's vertices and edges. New vertices and edges are created. */
	Graph(const Graph &other);

	/* Returns true if this graph contains the given vertex. */
	bool contains(const Vertex &vertex) const;

	/* Returns true if this graph contains the given edge. */
	bool contains(const Edge &edge) const;

	/* Returns true if an there is an edge between from and to of given 
	 * weight. */
	bool existsEdgeOfWeight(const Vertex &from,
							const Vertex &to,
							const int weight) const;

	/* Bubble sort algorithm. */
	void sortEdgeVector();

public:

	/* Returns a new graph which vertices and edges points to the given
	 * vertices and edges. */
	static Graph* of(const std::vector<Vertex*> &otherVertices,
					  const std::vector<Edge*> &otherEdges);

	/* Returns a new graph which vertices and edges are equal in value to
	 * other's vertices and edges. New vertices and edges are created. */
	static Graph* ofGraph(const Graph &other);

	/* Constructs a new vertex of given label and adds it to this graph. 
	 * Returns true if the vertex is effectivly added. */
	bool addVertex(const std::string &label);

	/* Adds an existing vertex to this graph if it is not already present.
	 * Returns true if it is effectivly added, false if it was already
	 * present. */
	bool addVertex(Vertex* const toAdd);

	/* Adds an existing edge to this graph if it is not already present.
	 * Returns true if it is effectivly added. */
	bool addEdge(Edge* const toAdd);

	/* Constructs a new edge with the existing vertices and weight and adds it
	 * to this graph. If an edge from 'from' vertex to 'to' vertex with the same
	 * weight already exists, the edge is not built nor added. 
	 * Returns true if the edge is effectivly added. */
	bool addEdge(Vertex &from, Vertex &to, const int weight);

	/* Constructs two new vertices and an edge binding them and adds the edge
	 * to this graph. */
	bool addEdge(const std::string fromLabel,
				 const std::string toLabel,
				 const int weight);

	/* Returns a pointer to the first vertex found with the given label. 
	 * If no vertices are found, returns nullptr. */
	Vertex* getVertexByLabel(const std::string label) const;

	/* Returns the sum of this graph edges' weights. */
	int weight() const;

	/* Symmetrizes this graph. For each edge (from, to, weight) of this graph, 
	 * if (to, from, weight) is not already an edge of this graph, it is 
	 * added. */
	void symmetrize();

	/* Kruskal implementation. Returns a vector of edges needed to form a
	 * minimal spanning tree of this graph. */
	std::vector<Edge*>* kruskal();

	/* Graph destructor. */
	virtual ~Graph();

	/* Graph print. */
	friend std::ostream& operator<<(std::ostream& out, const Graph &g);
};



#endif
