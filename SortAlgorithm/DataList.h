#ifndef DATELIST_H
#define DATELIST_H
#include "iostream"
#include "time.h"


using namespace std;

const int DefaultSize = 100;
template <typename T>
class Element {                             //数据表元素定义
public:

	Element<T>& operator =(Element<T> &x)	//元素x的值赋给this
	{
		key = x.key;
		otherdata = x.otherdata;
		return *this;
	}
	bool operator == (Element<T> &x)           //判断this与x是否相等
	{
		return key == x.key;
	}
	bool operator <=(Element<T> &x)				//判断this是否小于等于x
	{
		return key <= x.key;
	}
	bool operator > (Element<T> &x)				//判断this是否大于x
	{
		return key > x.key;
	}
	bool operator < (Element<T> &x)				//判断this是否小于x
	{
		return key < x.key;
	}
	/*friend istream &operator >>(istream &in, Element<T> &e)
	{
		in >> e.key>>e.otherdata;
		if (!in)
		{
			e.key = 0;
			e.otherdata = 0;
		}
		return in;
	}*/
	friend ostream &operator <<(ostream &out, Element<T> &e)
	{
		out <<  e.otherdata;
		return out;
	}

public:
	T key;                                  //排序码
	T otherdata;							//其它数据成员
};


template <class T>
class DataList {				 //数据表类型定义
public:
	DataList(int maxSz = DefaultSize) :maxSize(maxSz), currentSize(0)//构造函数
	{
		Vector = new Element<T>[maxSize];
	}

	DataList(T L[], int n)
	{
	
		maxSize = n;
		Vector = new Element<T>[maxSize * sizeof(Element<T>)];
		for (int i = 0; i < maxSize; i++)
		{
			Element<T> e;
			e.key = L[i];
			e.otherdata = L[i];
			Vector[i] = e;
		}
		MyPrint();
	}


	void Swap(Element<T> &x, Element<T> &y)//交换函数
	{
		Element<T> temp;
		temp = y;
		y = x;
		x = temp;
	}

	DataList<T>& operator =(DataList<typename T> other)
	{
		maxSize = other.maxSize;
		for(int i = 0;i<maxSize;i++)
		{
			Vector[i] = other.Vector[i];
		}
		return *this;
	}

	int Length() { return maxSize; }//取表长度

	Element<T> & operator [](int i)//重载[]符号，使其可以取地i个元素
	/*此处返回引用的原因是可以让返回值作左值*/
	{
		return Vector[i];
	}

	void randInitByInt()
	{
		srand(nullptr);
		int i;
		for (i = 0; i < this->Length(); i++)
		{
			Element<T> e;
			int data = rand() % 100;
			e.key = data;
			e.otherdata = data;
			Vector[i] = e;
		}
		maxSize = this->Length();
		MyPrint();
	}

	void MyPrint(bool iEnd = false)
	{
		return;
		if (!iEnd)
		{
			cout << "初始序列为：";
		}
		else {
			cout << "排序后序列为：";
		}
		
		for (int i = 0; i < Length(); i++)
		{
			cout << Vector[i] << ' ';
		}
		cout << endl;
	}

	int Partition(const int low, const int hight);//快速划分排序

private:
	Element<T> * Vector;						//存储排序元素的向量
	int maxSize;								//向量中最大元素个数
	int currentSize;							//当前元素个数
};

template <class T>
class Sort
{
public:
	friend class DataList<typename T>;
#pragma region 冒泡排序
	void BubbleSort1(DataList<T> &V, int n);
	void BubbleSort2(DataList<T> &V, int n);
#pragma endregion
	
#pragma region 插入排序
	void InsertSort(DataList<T> &L, const int left, const int right);
	void BinaryInsertSort(DataList<T> &L, const int left, const int right);
#pragma endregion
};



#endif // !DATEDATELIST_H

