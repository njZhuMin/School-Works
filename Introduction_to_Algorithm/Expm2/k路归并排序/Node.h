#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
public:
	Node* next;
	int data;

	Node();
	Node(int d);
	~Node();

	operator Node() const;
	bool operator < (const Node& temp);
	bool operator > (const Node& temp);
};

#endif // NODE_H
