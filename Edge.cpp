#include "Edge.hpp"

Edge::Edge(const std::string &fromLabel,
		   const std::string &toLabel,
		   const int weight):
	from {Vertex::ofLabel(fromLabel)},
	to {Vertex::ofLabel(toLabel)},
	weight {weight} {
    std::cout << "built " << *this << " from labels [" << fromLabel
			  << ", " << toLabel << "] and weight = " << weight << " [at "
			  << this << "]\n";
	GarbageCollector *gc {GarbageCollector::getInstance()};
	gc->addVertex(this->from);
	gc->addVertex(this->to);
	gc->addEdge(this);
}

Edge::Edge(Vertex* const from, Vertex* const to, const int weight):
	from {from},
	to {to},
	weight {weight} {
    std::cout << "built " << *this << " from vertices [" << *from
			  << " at " << from << ", " << *to << " at " << to
			  << "] and weight = " << weight << " [at " << this << "]\n";
	GarbageCollector *gc {GarbageCollector::getInstance()};
	gc->addEdge(this);
}

Edge::Edge(const Edge* const other):
	from {Vertex::ofVertex(other->from)},
	to {Vertex::ofVertex(other->to)},
	weight {other->weight} {
    std::cout << "built " << *this << " from edge [" << *other<< "] [at "
			  << this << "]\n";
	GarbageCollector *gc {GarbageCollector::getInstance()};
	gc->addVertex(this->from);
	gc->addVertex(this->to);	
	gc->addEdge(this);	
}

Edge* Edge::ofLabels(const std::string &fromLabel,
					 const std::string &toLabel,
					 const int weight) {
	return new Edge {fromLabel, toLabel, weight};
}

Edge* Edge::ofVertices(Vertex* const from,
					   Vertex* const to,
					   const int weight) {
	return new Edge {from, to, weight};
}

Edge* Edge::ofEdge(const Edge* const other) {
	return new Edge
		{Vertex::ofVertex(other->from),
		 Vertex::ofVertex(other->to),
		 other->weight};
}


Vertex* const Edge::getFrom() const {
    return from;
}

Vertex* const Edge::getTo() const {
    return to;
}

int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(const int weight) {
	this->weight = weight;
}

Edge::~Edge() {
    std::cout << "deleted edge ";
}

std::ostream& operator<<(std::ostream& out, const Edge &e) {
	out << *(e.from) << "---" << e.weight << "-->"<< *(e.to);
	return out;
}

