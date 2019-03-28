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
	SparseMatrix<T> Result(MaxTerms);
	if (Rows != b.Rows || Cols != b.Cols)
	{
		cout << "Incompatible matrices!" << endl;//矩阵规格不一致
		return Result;
	}
	int i = 0, j = 0, Index_a = 0, Index_b = 0;
	Result.Terms = 0;
	while (i < Terms&&j < b.Terms)
	{
		Index_a = Cols * SmArry[i].Row + SmArry[i].Col;
		Index_b = Cols * b.SmArry[j].Row + b.SmArry[j].Col;
		if (Index_a < Index_b)//a在b之前
		{
			Result.SmArry[Result.Terms] = SmArry[i];
			i++;
		}
		if (Index_a > Index_b)//a在b之后
		{
			Result.SmArry[Result.Terms] = b.SmArry[j];
			j++;
		}
		else
		{
			Result.SmArry[Result.Terms] = SmArry[i];
			Result.SmArry[Result.Terms].Value = SmArry[i].Value + b.SmArry[j].Value;
			i++; j++;
		}
		Result.Terms++;
	}
	for (; i < Terms; i++)
	{
		Result.SmArry[Result.Terms] = SmArry[i];
		Result.Terms++;
	}
	for (; j < Terms; j++)
	{
		Result.SmArry[Result.Terms] = b.SmArry[j];
		Result.Terms++;
	}
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
	int *RowSize = new int[Cols];//辅助数组，统计各列非零元素的个数
	int *RowStart = new int[Cols];//辅助函数，预计各列转置后各行存放的位置
	SparseMatrix<T> b(MaxTerms);
	b.Rows = Rows; b.Cols = Cols; b.Terms = Terms;
	if (Terms > 0)
	{
		int i, j;
		for (i = 0; i < Cols; i++)
		{
			RowSize[i] = 0;//初始化
		}
		for (j = 0; j < Terms; j++)
		{
			RowSize[SmArry[i].Col]++;//各列非零元素的个数
		}
		RowStart[0] = 0;
		for (i = 1; i < Cols; i++)
		{
			RowStart[i] = RowStart[i - 1] + RowSize[i - 1];
		}
		for (i = 0; i < Terms; i++)//从a向b传送
		{
			j = RowStart[SmArry[i].Col];//第i个非零元素在b中应放的位置
			b.SmArry[j].Row = SmArry[i].Col;
			b.SmArry[j].Col = SmArry[i].Row;
			b.SmArry[j].Value = SmArry[i].Value;
			RowStart[SmArry[i].Col]++;
		}

	}
	delete[] RowSize;
	delete[] RowStart;

	return b;
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
