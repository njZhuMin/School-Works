#ifndef EDGE_H
#define EDGE_H
#include <string>
using namespace std;

class Edge
{
public:
	string source;
	string sink;
	int capacity;
	string name;
	Edge* reverse;
	
	Edge(string src, string snk, int cap, Edge* rev)
	{
		source = src;
		sink = snk;
		capacity = cap;
		reverse = rev;
		name = src + snk;
	}
	
	bool operator == (Edge a) const
	{
		return sink == a.sink && source == a.source;
	}
	
	bool operator < (Edge a) const
	{
		return name < a.name;
	}
};

#endif // EDGE_H
