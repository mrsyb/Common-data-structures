#ifndef DATELIST_H
#define DATELIST_H
#include <iostream>

const int DefaultSize = 100;
template <class T>
class Element {                                 //数据表元素定义
public:
	T key;                                      //排序码
	T otherdata;                            //其它数据成员
	Element<T> & operator =(Element<T> &x)//元素x的值赋给this
	{
		key = x.key;
		other = x.other;
		return this;
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
};


template <class T>
class dataList {				 //数据表类型定义
public:
	dataList(int maxSz = DefaultSize) :maxSize(maxSz), currentSize(0)//构造函数
	{
		Vector = new Element<T>[maxSize];
	}

	void Swap(Element<T> &x, Element<T> &y)//交换函数
	{
		Element<T> temp;
		temp = y;
		y = x;
		x = temp;
	}

	int Length() { return maxSize; }//取表长度

	Element<T> & operator [](int i)//重载[]符号，使其可以取地i个元素
	/*此处返回引用的原因是可以让返回值作左值*/
	{
		return Vector[i];
	}

	/*friend istream &operator >>(istream &in, dataList <T> &L)
	{
		in >> L.Vector++;
		if (!in)
			L = dataList();
		return in;
	}


	friend ostream &operator <<(ostream &out, const dataList<T> &L)
	{
		if(L.Vector++ != NULL)
		out<<L.Vector++;
		return out;
	}*/


	int Partition(const int low, const int hight);//快速划分排序

private:
	Element<T> * Vector;						//存储排序元素的向量
	int maxSize;								//向量中最大元素个数
	int currentSize;							//当前元素个数
};
#endif // !DATEDATELIST_H
