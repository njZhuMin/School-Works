#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct HuffmanNode
{
	char data;
	double weight;
	int parent,lchild,rchild;
};

class HuffmanTree  
{
public:
	HuffmanTree(vector<HuffmanNode> &leafs);
	virtual ~HuffmanTree();
	vector<int> GetCode(int i);
	string DeCode(vector<int> &source);
	void SelectSmall(int &least,int &less);
private:
	vector<HuffmanNode> hufftree;
	int n;
};

