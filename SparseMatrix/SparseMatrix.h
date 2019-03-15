#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

const int DefaultSize = 100;
template<class T>
struct Trituple  
{
	int Row, Col;
	T Value;
	Trituple<T>& operator=(Trituple<T>& x)
	{
		Row = x.Row;
		Col = x.Col;
		Value = x.Value;
	}
};

template<class T>
class SparseMatrix 
{
	friend ostream& operator << (ostream& out, SparseMatrix<T>& M);
	friend istream& operator >> (istream& in, SparseMatrix<T>& M);

public:
	SparseMatrix(int MaxSz = DefaultSize);
	SparseMatrix(SparseMatrix<T>& X);
	~SparseMatrix() { delete []SmArry; }
	SparseMatrix<T>& operator =(SparseMatrix<T>& X);
	SparseMatrix<T> Transpose();//转置
	SparseMatrix<T> FastTranspose();//快速转置
	SparseMatrix<T> Add(SparseMatrix<T>& b);//相加
	SparseMatrix<T> Multiply(SparseMatrix<T>& b);//c[i][j] = Sum(a[i][k]*b[k][j])
private:
	int Rows, Cols, Terms;
	Trituple<T> *SmArry;
	int MaxTerms;
};



