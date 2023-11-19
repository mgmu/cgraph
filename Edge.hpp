#ifndef _EDGE
#define _EDGE

#include <iostream>
#include <string>
#include "Vertex.hpp"
#include "GarbageCollector.hpp"

class Edge {

private:

	/* The vertex this edge comes from. */
	Vertex* const from;

	/* The vertex this edge goes to. */
	Vertex* const to;
	
	/* The weight of this edge. */
	mutable int weight;

	/* Constructs a new edge of given weight, which from and to vertices points
	 * to newly created vertices of respective labels. */
	Edge(const std::string &fromLabel,
		 const std::string &toLabel,
		 const int weight);

	/* Constructs a new edge of given weight which vertices points
	 * to the given vertices.
	 * Note that a modification in one of the two edges reverberates on
	 * the other. */
	Edge(Vertex* const from, Vertex* const to, const int weight);

	/* Constructs a new edge of weight equal to other's weight, which from and to
	 * vertices points to newly created vertices of other's from and to labels. */
	Edge(const Edge* const other);

public:

	/* Returns a new edge of given weight, which from and to vertices points
	 * to newly created vertices of respective labels. */
	static Edge* ofLabels(const std::string &fromLabel,
						  const std::string &toLabel,
						  const int weight);

	/* Returns a new edge of given weight which vertices points
	 * to the given vertices.
	 * Note that a modification in one of the two edges reverberates on
	 * the other. */
	static Edge* ofVertices(Vertex* const from,
							Vertex* const to,
							const int weight);

	/* Returns a new edge of weight equal to other's weight, which from and to
	 * vertices points to newly created vertices of other's from and to labels. */
	static Edge* ofEdge(const Edge* const other);

	/* Returns a pointer to the vertex this edge comes from. */
	Vertex* const getFrom() const;

	/* Returns a pointer to the vertex this edge goes to. */
	Vertex* const getTo() const;

	/* Returns the weight of this edge. */
	int getWeight() const;

	/* Sets the weight of this edge to the given weight value. */
	void setWeight(const int weight);

	/* Edge destructor. */
	virtual ~Edge();

	/* Edge print. */
	friend std::ostream& operator<<(std::ostream& out, const Edge &e);

};

#endif
