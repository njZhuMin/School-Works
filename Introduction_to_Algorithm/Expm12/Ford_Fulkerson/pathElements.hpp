#ifndef PATHELEMENTS_H
#define PATHELEMENTS_H
#include <vector>
using namespace std;

class pathElements
{
public:
	vector<Edge*> edges;
	int residual;
	
	pathElements(vector<Edge*> path, int res)
	{
		edges = path;
		residual = res;
	}
};

#endif // PATHELEMENTS_H
