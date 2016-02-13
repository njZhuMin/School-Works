#include "Huffmantree.h"
#include <iostream>
using namespace std;

int main()
{
	int i;
	HuffmanNode hn[5];
	hn[0].data = 'A';
	hn[0].weight = 0.2;
	hn[1].data = 'B';
	hn[1].weight = 0.3;
	hn[2].data = 'C';
	hn[2].weight = 0.4;
	hn[3].data = 'D';
	hn[3].weight = 0.1;
	for(i = 0; i < 4; i++)
	{
		hn[i].parent = hn[i].rchild = hn[i].lchild = -1;
	}
	
	vector <HuffmanNode> leaves;
	for(i = 0; i < 4; i++)
	{
		leaves.push_back(hn[i]);		
	}
	HuffmanTree ht1(leaves);
	
	//Huffman Code
	for(i = 0; i < 4; i++)
	{
		vector<int> hc = ht1.GetCode(i);
		cout << "Huffman code of " << hn[i].data << " is: ";
		for(unsigned int j = 0; j < hc.size(); j++)
			cout << hc[j];
		cout << endl;
	}
	
	//Huffman Decode
	cout << "Character of huffman code 011 is ";
	vector<int> source ;
	source.push_back(0);
	source.push_back(1);
	source.push_back(1);
	cout << ht1.DeCode(source) << endl;
	
	return 0;
}