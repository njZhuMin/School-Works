//杨辉三角递归实现
#include <iostream>
using namespace std;

int fun(int,int);

int main()
{ 
	int i,j,k,n; 
	cout << "Input line number:" <<endl;
	cin >> n; 
	for(i=0; i<n; i++) 
	{ 
		for(j=0; j<=2*n-2*i; j++) 
			cout <<" "; 
		for(k=0; k<=i; k++) 
			cout <<" " << fun(i,k) <<"  "; 
		cout << "\n"; 
	} 
	return 0;
}

int fun(int i,int j)
{ 
	if(j==0) 
		return 1; 
	else 
		return fun(i,j-1)*(i-j+1)/j;
}