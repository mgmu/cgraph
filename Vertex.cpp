#include "Vertex.hpp"
#include "GarbageCollector.hpp"

Vertex::Vertex(const std::string label): mark {0}, label {label} {
	std::cout << "built " << *this << " from label \"" << label << "\" ["
			  << this << "]\n";
	GarbageCollector *gc {GarbageCollector::getInstance()};
	gc->addVertex(this);
}

Vertex::Vertex(const Vertex* const other):
	mark {other->mark},
	label {other->label} {
	std::cout << "built " << *this << " from vertex [" << *other << " at "
			  << other << "] [" << this << "]\n";
	GarbageCollector *gc {GarbageCollector::getInstance()};
	gc->addVertex(this);
}

Vertex* Vertex::ofLabel(const std::string label) {
	return new Vertex {label};
}

Vertex* Vertex::ofVertex(const Vertex* const other) {
	return new Vertex {other};
}

int Vertex::getMark() const {
	return mark;
}

std::string Vertex::getLabel() const {
	return label;
}

Vertex::~Vertex() {
	std::cout << "deleted vertex ";
}

void Vertex::setMark(const int mark) {
	this->mark = mark;
}

void Vertex::setLabel(const std::string label) {
	this->label = label;
}

std::ostream& operator<<(std::ostream& out, const Vertex &v) {
	out << "|" << v.label << "|";
	return out;
}
