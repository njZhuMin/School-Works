#include <iostream>
#include "SparseMatrix.cpp"
using namespace std;

int main()
{
	int row = 3;
	int col = 3;
	Triple<int> t[3];
	
	for(int i =0;i<3;i++)
	{
		do {
			cout << "Input the " << i+1 << "th non-zero element row number:";
			cin >> t[i].r;
			cout << "Input the " << i+1 << "th non-zero element column number:";
			cin >> t[i].c;          
			cout << "Elements:";
			cin >> t[i].elem;
			if(t[i].r < 0 || t[i].r > row || t[i].c < 0 || t[i].c > col)
				cout << "Error row number or column number!" << endl;
		} while(t[i].r < 0 || t[i].r > row || t[i].c < 0 || t[i].c > col); 
	
	}
	SparseMatrix<int> sm(t,3,3,3);
	sm.print();
	
	cout << "After transform:" << endl;
	sm.trans(sm);
	sm.print();

	cout << "After self-plus:" << endl;
	sm.plus(sm);
	sm.print();

	cout << "After self-multiply:" << endl;
	sm.mult(sm);
	sm.print();
	return 0;
}