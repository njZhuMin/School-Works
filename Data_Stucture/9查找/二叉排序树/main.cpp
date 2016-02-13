#include <iostream>
#include "BiSortTree.h"
using namespace std; 

int main()
{
	int i;  
	int nodeArray[11] = {15,6,18,3,7,17,20,2,4,13,9};  
	BiSortTree bt(nodeArray,11);  
	for(i = 0; i < 2 ; i++)  
		bt.Delete(nodeArray[i]);  
	cout << bt.searchMin()->key << endl;  
	cout << bt.searchMax()->key << endl;  
	cout << bt.recursiveSearch(13) << endl;  
	return 0;  
}