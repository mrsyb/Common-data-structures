#ifndef _SEQLIST_CPP
#define _SEQLIST_CPP

#include "SeqList.h"

template<class T>
 SeqList<T>::SeqList(int Sz)
{
	if (Sz > 0)
	{
		MaxSize = Sz;
		Last = -1;
		Data = new (std::nothrow)T[MaxSize];
		if (Data == nullptr)
		{
			std::cerr << "内存分配失败"<<std::endl;
			return;
		}
	}
}

template<class T>
 SeqList<T>::SeqList(SeqList<T>& L)
{
	MaxSize = L.Size();
	Last = L.Length();
	Data = new (std::nothrow) T[MaxSize];
	if (Data == nullptr)
	{
		std::cerr << "内存分配错误！" << std::endl;
		return;
	}

	T value;
	for (int i = 0; i <= MaxSize; i++)
	{
		L.GetData(i, value);
		SetData(i, value);
	}

}

template<class T>
 SeqList<T>::~SeqList()
{
	 delete[] Data;
}

template<class T>
LinearList<T>& SeqList<T>::operator=(LinearList<T>& other)
{
	 if (&other == this)return *this;

	 MaxSize = other.Size();
	 Last = other.Length();

	 delete[] Data;

	 Data = new(std::nothrow) T[MaxSize];
	 if (Data == nullptr)
	 {
		 std::cerr << "内存分配错误！" << std::endl;
		 return *this;
	 }

	 T value;
	 for (int i = 0; i < MaxSize; i++)
	 {
		 other.GetData(i, value);
		 Data[i] = value;
	 }
	 return *this;
}

template<class T>
void SeqList<T>::reSize(int NewSize)
{
	if (NewSize < 0)
	{
		std::cerr << "无效的数组长度！" << std::endl;
		return;
	}
	if (NewSize != MaxSize) 
	{
		T* NewArry = new(std::nothrow) T[NewSize];
		if (NewArry == nullptr)
		{
			std::cerr << "无效的数组长度！" << std::endl;
			return;
		}

		int n = Last;
		while (Last--)
		{
			*NewArry++ = *Data++;
		}
		delete[] Data;
		Data = NewArry;
		MaxSize = NewSize;

	}
}

template<class T>
 int SeqList<T>::Search(const T & x) const
{
	 for (int i = 0; i <= Last; i++) 
	 {
		 if (Data[i] == x)
			 return i;
	 }
	return 0;
}


template<class T>
 bool SeqList<T>::Insert(int i, const T& x)
{
	 if (i > -1 && i <= Last)
	 {
		 int n = Last;
		 while (n >= i)
		 {
			 Data[n+1] = Data[n];
			 n--;
		 }
		 Data[n+1] = x;
		 Last += 1;
		 return true;
	 }
	 else
	 {
		 std::cerr << "index out range!"<<std::endl;
		 return false;
	 }
}

template<class T>
 bool SeqList<T>::Remove(int i, T & x)
{
	 if (i > -1 && i <= Last)
	 {
		 x = Data[i];
		 for (int j = i; j <= Last; j++)
		 {
			 Data[j] = Data[j + 1];
		 }
		 Last -= 1;
		 return true;
	 }
	 else
	 {
		 std::cerr << "index out range!"<<std::endl;
		 return false;
	 }
}



template<class T>
 void SeqList<T>::Input()
{
	 int len = 0;
	 std::cout << "请输入顺序表元素个数（0-" << MaxSize - 1 <<")"<< std::endl;
	 std::cin >> len;
	 Last = len - 1;
	 std::cout << "请输入" << len << "个数" << std::endl;
	 for (int i = 0;i<= Last;i++)
	 {
		 std::cin >> Data[i];
	 }
}

template<class T>
 void SeqList<T>::Output()
{
	for (int i= 0;i <= Last;i++)
	{
		std::cout <<"#"<<i<<" : "<< Data[i]<< std::endl;
	}
}

#endif // _SEQLIST_CPP

