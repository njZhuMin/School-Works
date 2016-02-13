#include "SparseMatrix.h"

template<class T>
SparseMatrix<T>::SparseMatrix()
{
	
}

template<class T>
SparseMatrix<T>::~SparseMatrix()
{
		
}

template<class T>
SparseMatrix<T>::SparseMatrix(Triple<T>* tlist, int rs, int cs, int n)
{
	this->cols = cs;
	this->rows = rs;
	this->num = n;	
	if(cs<0 || rs<0 || n<0 || n > rs*cs)
	{
		cout << "Error Matrix!" << endl;
		exit(1);
	}
	if (n == 0) 
		return;
	for (int i = 0; i < n; i++)
	{
		triList.push_back(tlist[i]);
	}
	
}

//矩阵转置
template<class T>
void SparseMatrix<T>::trans(SparseMatrix<T> &B)
{
	B.rows = this->cols;
	B.cols = this->rows;
	B.num = this->num;
	B.triList.resize(num);
	if(num == 0)
		return;
	int* cnum = new int [cols];
	int* cpot = new int [cols];
	for(int col = 0; col < cols; ++col)
	{
		cnum[col] = 0;
	}
	for(int t = 0; t < num; ++t)
	{
		++cnum[triList[t].c];
	}
	cpot[0] = 0;
	for(int col = 1; col < cols; ++col)
		cpot[col] = cpot[col-1] + cnum[col-1];
	for(int p = 0; p < num; ++p)
	{
		int col = triList[p].c;
		int q = cpot[col];
		B.triList[q].r = triList[p].c;
		B.triList[q].c = triList[p].r;
		B.triList[q].elem = triList[p].elem;
		++cpot[col];
	}
	delete[] cnum;
	delete[] cpot;
}

template<class T>
void SparseMatrix<T>::print()
{
	int i,j,k=0;
	for(i=0; i<rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			if(i == triList[k].r  &&  j == triList[k].c)
			{
				cout << triList[k].elem << "  ";
				k++;
			}
			else
				cout << "0" << "  ";
		}
		cout << endl;
	}
}

template<class T>
SparseMatrix<T> &SparseMatrix<T>::plus(SparseMatrix &B)
{
	int i,j,k=0;
	if(B.cols!=cols || B.rows!=rows)
	{
		cout << "Error calculation!" << endl;
		exit(1);
	}
	else
	{
		for(i = 0; i < rows; i++)
		{
			for(j = 0; j < cols; j++)
			{
				if((i == triList[k].r  &&  j == triList[k].c)  || (i ==	B.triList[k].r  &&  j == B.triList[k].c))
				{
					B.triList[k].elem += triList[k].elem ;
					k++;
				}
			}
		}
	}
	return B;
}

template<class T>
SparseMatrix<T> &SparseMatrix<T>::mult(SparseMatrix &B) //矩阵乘法
{
	int i,j,k=0;
	if(B.cols!=rows || B.rows!=cols)
	{
		cout << "Error calculation!" << endl;
		exit(1);
	}
	else 
	{
		for(i = 0; i < cols; i++)
		{
			for(j = 0; j < rows; j++)
			{
				if((i == B.triList[k].c  &&  j == triList[k].r)  )
				{
					B.triList[k].elem = B.triList[k].elem*triList[k].elem ;
					k++;
				}
			}
		}	
	}
	return B;
}