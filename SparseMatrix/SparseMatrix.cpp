#include "SparseMatrix.h"


template<class T>
SparseMatrix<T>::SparseMatrix(int MaxSz /*= DefaultSize*/):MaxTerms(MaxSz)
{
	if (MaxSz<1)
	{
		cerr << "Initialize fail! " << endl;
		exit(1);
	}
	SmArry = new (nothrow)Trituple<T>[MaxSz];
	if (SmArry == nullptr)
	{
		cerr << "Malloc Failure! " << endl;
		exit(1);
	}
	Rows = Cols = Terms = 0;
}

template<class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T>& X)
{
	Rows = X.Rows;
	Cols = X.Cols;
	Terms = X.Terms;
	MaxTerms = X.MaxTerms;
	SmArry = new (nothrow)Trituple<T>[X.MaxTerms];
	if (SmArry)
	{
		cerr << "Malloc Failure!" << endl;
		exit(1);
	}
	for (int i = 0;i<MaxTerms;i++)
	{
		SmArry[i] = X.SmArry[i];
	}
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Multiply(SparseMatrix<T>& b)
{

}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix<T>& b)
{

}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Transpose()
{
	SparseMatrix<T>b(MaxTerms);
	b.Rows = Cols;
	b.Cols = Rows;
	if (Terms > 0)
	{
		int k, i, CurretB = 0;
		for (int i = 0;i<Cols;i++)
		{
			for (int k = 0; k < Terms; k++)
			{
				if (SmArry[k].Col == i)
				{
					b.SmArry[CurretB].Row = i;
					b.SmArry[CurretB].Col = b.SmArry[CurretB].Row;
					++CurretB;
				}
			}
		}
		return b;
	}
}


template<class T>
SparseMatrix<T> SparseMatrix<T>::FastTranspose()
{

}

template<class T>
SparseMatrix<T>& SparseMatrix<T>::operator=(SparseMatrix<T>& X)
{

}

template<class T>
ostream & operator<<(ostream & out, SparseMatrix<T>& M)
{
	out << "Rows = " << M.Rows << endl;
	out << "Cols = " << M.Cols << endl;
	out << "Nonzero terms = " << M.Terms << endl;
	for (int i = 0; i < M.Terms; i++)
	{
		out << "M[" << M.SmArry[i].Row << "][" << M.SmArry[i].Col << "]=" << M.SmArry[i].Value << endl;
	}
	return out;
}

template<class T>
istream & operator>>(istream & in, SparseMatrix<T>& M)
{
	cout << "Enter number of rows,cols,terms." << endl;
	in >> M.Rows >> M.Cols >> M.Terms;
	if (M.Terms > M.MaxTerms)
	{
		cerr << "Number of terms overflow!" << endl;
		exit(1);
	}
	for (int i = 0;i<M.Terms;i++)
	{
		cout << "Enter Rows,Cols,Value." << i + 1 << endl;
		in >> M.SmArry[i].Row >> M.SmArry[i].Col >> M.SmArry[i].Value >> endl;
	}
	return in;
}
