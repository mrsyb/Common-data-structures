#pragma once
template <class T>
class LinearList 
{
public:
	/*LinearList();
	~LinearList();*/
	/** 最大体积*/
	virtual int Size()const { return 0; };
	/** 表长度*/
	virtual int Length() const { return 0; };
	/** 在表中搜索给定值X*/
	virtual int Search(const T& x)const { return 0; };
	/** 在表中定位第i个元素的位置*/
	virtual int Locate(int i) const { return 0; };
	/** 取第i个表项的值*/
	virtual bool GetData(int i, T& x) { return 0; };
	/** 修改第i个表项的值*/
	virtual void SetData(int i, const T& x){};
	/** 在第i个表项后插入x*/
	virtual bool Insert(int i, const T& x) { return 0; };
	/** 删除第i个表项通过x返回*/
	virtual bool Remove(int i, T&x) { return 0; };
	virtual bool IsEmpty() { return 0; };
	virtual bool IsFull() { return 0; };
	virtual void Sort(){};
	/** 输入*/
	virtual void Input(){};
	/** 输出*/
	virtual void Output() { std::cout << "LinearList->Output()"; };
	/** 复制，若不返回引用类型编译报错，不能创建抽象类的实例。抽象类型不能用作参数类型、函数返回类型或显式转换的类型。可以声明到抽象类的指针或引用。*/
	virtual LinearList<T>& operator=(LinearList<T> &L) { return *this; };
};