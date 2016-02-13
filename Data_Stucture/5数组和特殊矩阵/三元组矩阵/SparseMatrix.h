#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct Triple
{
	int r,c;
	T elem;
};

template<class T>
class SparseMatrix
{
public:
	SparseMatrix();
	virtual ~SparseMatrix();
	SparseMatrix(Triple<T>* tlist, int rs, int cs, int n);
	void trans(SparseMatrix<T>&B);
	SparseMatrix& plus(SparseMatrix &B);
	SparseMatrix& mult(SparseMatrix &B);
	void print();
private:
	vector<Triple<T> > triList;
	int rows;
	int cols;
	int num;
};

#endif // SPARSEMATRIX_H
