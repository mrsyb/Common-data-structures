#ifndef _SEQLIST_H
#define _SEQLIST_H

#include <iostream>
#include <stdlib.h>
#include "LinearList.h"
const int DefaultSize = 100;

template <class T>
class SeqList :public LinearList<T>
{
public:
	SeqList(int Sz = DefaultSize);
	SeqList(SeqList<T>& L);
	~SeqList();
	LinearList<T>& operator= (LinearList<T>& other) override;
public:
	int Size()const override { return MaxSize; };//最大容量
	int Length()const override { return Last + 1; };
	int Search(const T& x)const override;//返回索引
	bool GetData(int i, T& x) override { if (i >= 0 && i < Last + 1) { x = Data[i]; return true; } else return false; }
	void SetData(int i, const T& x) override { if (i >= 0 && i < Last + 1) { Data[i] = x; } }
	bool IsFull() override { if (Last == MaxSize - 1)return true; return false; }
	bool IsEmpty()override { if (Last == -1)return true; return false; }

	bool Insert(int i, const T& x)override;
	bool Remove(int i, T& x)override;

	//不要求保持原有顺序时直接插入到最后一位，效率O(1)
	bool Insert2(const T x) { if (++Last <= MaxSize) { Data[Last + 1] = x; return true; }return false; };
	//不要求保持原有顺序时直接用最后一位覆盖掉第i位，效率O(1)
	bool Remove2(int i, T& x) { if (i >= 0 && i < Last + 1) { Data[i] = Data[Last]; return true; }return false; };

	void Input ()override;
	void Output ()override;

protected:
	T* Data;
	int MaxSize;
	int Last;
	void reSize(int NewSize);

};

#endif