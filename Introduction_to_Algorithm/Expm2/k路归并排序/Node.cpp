#include "Node.h"

Node::Node()
{
	next = NULL;
}

Node::Node(int d)
{
	data = d;
	next = NULL;
}

Node::~Node()
{
	
}

Node::operator Node() const
{
	return data;
}

bool Node::operator < (const Node& temp)
{
	return data < temp.data;
}

bool Node::operator > (const Node& temp)
{
	return data > temp.data;
}
