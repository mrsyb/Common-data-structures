#pragma once
template <class T>
class LinearList 
{
public:
	LinearList();
	~LinearList();
	/** 最大体积*/
	virtual int Size()const = 0;
	/** 表长度*/
	virtual int Length() const = 0;
	/** 在表中搜索给定值X*/
	virtual int Search(T& x)const = 0;
	/** 在表中定位第i个元素的位置*/
	virtual int Locate(int i) const = 0;
	/** 取第i个表项的值*/
	virtual bool GetData(int i, T& x)const = 0;
	/** 修改第i个表项的值*/
	virtual void SetData(int i,T& x) = 0;
	/** 在第i个表项后插入x*/
	virtual bool Insert(int i, T&x) = 0;
	/** 删除第i个表项通过x返回*/
	virtual bool Remove(int i, T&x) = 0;
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull()const = 0;
	virtual void Sort() = 0;
	/** 输入*/
	virtual void Input() = 0;
	/** 输出*/
	virtual void Output() = 0;
	/** 复制，若不返回引用类型编译报错，不能创建抽象类的实例。抽象类型不能用作参数类型、函数返回类型或显式转换的类型。可以声明到抽象类的指针或引用。*/
	virtual LinearList<T>& operator=(LinearList<T> &L) = 0;
};