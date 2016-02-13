#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(vector<HuffmanNode> &leafs)
{
	int i;
	int n = leafs.size();
	hufftree.resize(2 * n - 1);
	for(i=0; i<n; i++)
	{
		hufftree[i].data   = leafs[i].data;
		hufftree[i].weight = leafs[i].weight;
		hufftree[i].parent = hufftree[i].lchild = hufftree[i].rchild = -1;
	}

	for(i=n; i<2*n-1; i++)
	{
		int least=0,less=0;
		SelectSmall(least,less);
		hufftree[least].parent = hufftree[less].parent = i;
		hufftree[i].parent = -1;
		hufftree[i].lchild = least;
		hufftree[i].rchild = less;
		hufftree[i].weight = hufftree[least].weight + hufftree[i].weight;
	}
}


void HuffmanTree::SelectSmall(int &least,int &less)
{
	//寻找最小根的下标
	int i;
	int n = hufftree.size();
	for(i=0; i<n; i++)
	{
		if(hufftree[i].parent == -1) 
			break;
	}
	for(least=i, i++; i<n; i++)
	{
		if(hufftree[i].parent == -1 && hufftree[i].weight < hufftree[least].weight)
		{	
			least = i;	
			}
	}
	//寻找次小根的下标
	for(i=0; i<n; i++)
	{// !=least结点!
		if(hufftree[i].parent == -1 && i != least)
			break;
	}
	for(less=i,i++; i<n; i++)
	{
		if(hufftree[i].parent == -1 && i != least && hufftree[i].weight < hufftree[less].weight)
			less = i;
	}
}

HuffmanTree::~HuffmanTree()
{

}

vector<int> HuffmanTree::GetCode(int i)
{
	vector<int>code;
	int p = i;
	int parent = hufftree[i].parent;
	while(parent != -1)
	{
		if(hufftree[parent].lchild == p)
			code.insert(code.begin(),0);
		else
			code.insert(code.begin(),1);
		p = parent;
		parent = hufftree[parent].parent;
	}
	return code;
}

string HuffmanTree::DeCode(vector<int> &source)
{
	string target = "";
	unsigned int i;
	int root = hufftree.size()-1;
	int p = root;
	for(i = 0; i < source.size(); i++)
	{
		if(source[i] == 0)
			p = hufftree[p].lchild;
		else
			p = hufftree[p].rchild;
		if(hufftree[p].lchild ==-1 && hufftree[p].rchild ==-1)
		{
			target += hufftree[p].data;
			p = root;
		}
	}
	return target;
}