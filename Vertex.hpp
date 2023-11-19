#ifndef _VERTEX
#define _VERTEX

#include <iostream>
#include <string>

class Vertex {

private:

	/* The mark of this vertex. */
	mutable int mark;

	/* The label of this vertex. */
	mutable std::string label;

	/* Constructs a new vertex of given label. */
	Vertex(const std::string label);

	/* Constructs a new vertex of other's label. */
	Vertex(const Vertex* const other);

public:

	/* Returns a new vertex of given label. */
	static Vertex* ofLabel(const std::string label);

	/* Returns a new vertex of other's label. */
	static Vertex* ofVertex(const Vertex* const other);

	/* Returns the mark value of this vertex. */
	int getMark() const;

	/* Returns the label value of this vertex. */
	std::string getLabel() const;

	/* Sets the mark of this vertex to the given mark value. */
	void setMark(const int mark);

	/* Sets the label of this vertex to the given label value. */
	void setLabel(const std::string label);

	/* Vertex destructor */
	virtual ~Vertex();

	/* Vertex print */
	friend std::ostream& operator<<(std::ostream& out, const Vertex &v);
};

#endif 

