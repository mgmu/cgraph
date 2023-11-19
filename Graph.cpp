#include "Graph.hpp"

Graph::Graph(const std::vector<Vertex*> &otherVertices,
		const std::vector<Edge*> &otherEdges): vertices {}, edges {} {
	for (Vertex* const v : otherVertices)
		vertices.push_back(v);
	for (Edge* const e : otherEdges)
		edges.push_back(e);
	std::cout << "built graph [at " << this << "] from vectors\n";
}

Graph::Graph(const Graph &other): vertices {}, edges {} {
	for (Vertex* const v : other.vertices)
		addVertex(v);
	for (Edge* const e : other.edges)
		addEdge(e);
	std::cout << "built graph [at " << this << "] from graph [at "
			  << &other << "]\n";
}

bool Graph::contains(const Vertex &vertex) const {
	for (const Vertex* const v : vertices)
		if (v == &vertex) return true;
	return false;
}

bool Graph::contains(const Edge &edge) const {
	for (const Edge* const e : edges)
		if (e == &edge) return true;
	return false;
}	

bool Graph::existsEdgeOfWeight(const Vertex &from,
							   const Vertex &to,
							   const int weight) const {
	if (!contains(from) || !contains(to)){
		return false;
	}
	for (Edge* const edge : edges) {
		if (edge->getFrom() == &from
			&& edge->getTo() == &to
			&& edge->getWeight() == weight) {
			return true;
		}
	}
	return false;
}


Graph* Graph::of(const std::vector<Vertex*> &otherVertices,
				 const std::vector<Edge*> &otherEdges) {
	return new Graph {otherVertices, otherEdges};
}

Graph* Graph::ofGraph(const Graph &other) {
	return new Graph {other};
}

bool Graph::addVertex(const std::string &label) {
	Vertex* const v {Vertex::ofLabel(label)};
	vertices.push_back(v);
	return true;
}

bool Graph::addVertex(Vertex* const toAdd) {
	if (contains(*toAdd))
		return false;
	vertices.push_back(toAdd);
	return true;
}

bool Graph::addEdge(Edge* const toAdd) {
	if (contains(*toAdd))
		return false;
	addVertex(toAdd->getFrom());
	addVertex(toAdd->getTo());
	edges.push_back(toAdd);
	return true;
}

bool Graph::addEdge(Vertex &from,  Vertex &to, const int weight) {
	if (existsEdgeOfWeight(from, to, weight)){
		return false;
	}
	addVertex(&from);
	addVertex(&to);
	edges.push_back(Edge::ofVertices(&from, &to, weight));
	return true;
}

bool Graph::addEdge(const std::string fromLabel,
					const std::string toLabel,
					const int weight) {
	Vertex* const from {Vertex::ofLabel(fromLabel)};
	Vertex* const to {Vertex::ofLabel(toLabel)};
	addVertex(from);
	addVertex(to);
	return addEdge(*from, *to, weight);
}

Vertex* Graph::getVertexByLabel(const std::string label) const {
	for (Vertex* const vertex : vertices)
		if ((vertex->getLabel()).compare(label) == 0) return vertex;
	return nullptr;
}

int Graph::weight() const {
	int total {0};
	for (const Edge* const edge : edges)
		total += edge->getWeight();
	return total;
}

void Graph::symmetrize() {
	std::cout << "Symmetrizing...\n";
	Edge *e {nullptr};
	for (size_t i {0}; i < edges.size(); i++) {
		e = edges[i];
		addEdge(*(e->getTo()), *(e->getFrom()), e->getWeight());
	}
	std::cout << "Finished symmetrizing !\n";
}

Graph::~Graph() {
	std::cout << "deleted graph\n";
}

std::ostream& operator<<(std::ostream &out, const Graph &g) {
	out << "Graph (V, E)\nV = {\n";
	for (const Vertex* const v : g.vertices) {
		out << "    " << *v << " [at " << v << "]\n";
	}
	out << "}\nE = {\n";
	for (const Edge* const e : g.edges) {
		out << "    " << *e << " [at " << e << "]\n";
	}
	return out << "}\n";
}

std::vector<Edge*>* Graph::kruskal() {
	symmetrize();
	std::vector<Edge*> *res {new std::vector<Edge*>};
	int i{0};
	for (Vertex* const v : vertices) {
		v->setMark(i);
		i++;
	}
	
	sortEdgeVector();
	for (Edge* const e : edges) {
		Vertex *u {e->getFrom()};
		Vertex *v {e->getTo()};

		int markU {u->getMark()};
		int markV {v->getMark()};

		if (markU != markV) {
			res->push_back(e);
			for (Edge *e1 : edges)
				if (e1->getFrom() == v && e1->getTo() == u)	res->push_back(e1);
			for (Vertex *v1 :vertices) {
				if (v1->getMark() == markU || v1->getMark() == markV)
					v1->setMark(u->getMark());
			}
		}
	}
	return res;
}

void Graph::sortEdgeVector(){
	for (size_t i {0}; i < edges.size()-1; i++){
        for (size_t j {0}; j < edges.size()-i-1; j++) {
            if (edges[j]->getWeight() > edges[j+1]->getWeight())
                iter_swap(edges.begin()+j, edges.begin()+j+1);
        }
    }
}

