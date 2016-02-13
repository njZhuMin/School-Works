#include <iostream>
#include <algorithm>
#include "Edge.hpp"
#include "pathElements.hpp"
#include "Network.hpp"

using namespace std;

int main()
{
	Network N= Network();
	N.addEdges("s", "o", 3);
	N.addEdges("s", "p", 4);
	N.addEdges("o", "p", 4);
	N.addEdges("o", "q", 5);
	N.addEdges("p", "r", 3);
	N.addEdges("r", "t", 3);
	N.addEdges("q", "r", 4);
	N.addEdges("q", "t", 3);

	//N.display();
	cout << "The max flow in graph is: " << N.max_flow("s", "t") << endl;
	return 0;
}
