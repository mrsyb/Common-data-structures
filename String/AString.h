#pragma once
#include <cstring>
#define DefaultSize 128
class Astring
{
public:
	Astring(int Sz = DefaultSize);
	Astring(const char* other);
	Astring(const Astring& other);
	~Astring() { delete[] ch; };
	int Length()const { return CurLength; }
	Astring& operator()(int pos, int len);//返回从pos开始往后len个长度的子串
	int operator == (Astring & other)const { return strcmp(ch, other.c_str())==0; }
	char* c_str() const{ return ch; }
	int operator !=(Astring& other)const { return strcmp(ch, other.c_str())!= 0; }
	Astring & operator=(Astring& other);
	int Find(Astring& other)const;//若串other与*this中某个子串匹配，则返回第一次出现该子串的位置，否则返回-1
	char& operator[](int i)const;

private:
	char* ch;
	int CurLength;
	int MaxSize;
};

