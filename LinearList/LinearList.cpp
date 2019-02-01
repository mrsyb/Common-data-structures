// LinearList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "SeqList.h"
#include "SeqList.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"

#include <iostream>
using namespace std;

int main()
{
#pragma region SeqList
/*
	SeqList<int> * MySeqList = new SeqList<int>(10);
	int a = 99999;
	int b = 0;

	cout << "构造————————————————————————————" << endl;
	MySeqList->Input();
	MySeqList->Output();

	cout << "插入————————————————————————————" << "99999" << endl;
	MySeqList->Insert(3, a);
	MySeqList->Output();

	cout << "查找————————————————————————————" << "99999" << endl;
	cout << "Index：" << MySeqList->Search(a) << endl;

	cout << "删除————————————————————————————" << "99999" << endl;
	MySeqList->Remove(3, b);
	MySeqList->Output();
*/
#pragma endregion SeqList
#pragma region LinkedList
	List<int>* MyLinkList = new List<int>();

	cout << "构造前插输入0结束————————————————————————————"<< endl;
	MyLinkList->InputFront(0);
	MyLinkList->Output();
	cout << "构造后插输入0结束————————————————————————————" << endl;
	MyLinkList->InputRear(0);
	MyLinkList->Output();
	cout << "插入————————————————————————————99999" << endl;
	int a = 99999;
	MyLinkList->Insert(2,a);
	MyLinkList->Output();
	cout << "删除————————————————————————————99999" << endl;
	int b;
	MyLinkList->Remove(3, b);
	MyLinkList->Output();
#pragma endregion LinkedList

	return 0;
}
