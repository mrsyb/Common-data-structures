#include "AString.h"

Astring::Astring(int Sz /*= DefaultSize*/):MaxSize(Sz)
{
	ch = new (std::nothrow)char[MaxSize];
	if (ch == nullptr)
	{
		exit(1);
	}
	ch[0] = '\0';
	CurLength = 0;
}

Astring::Astring(const char* other)
{
	int n = strlen(other);
	MaxSize = n > 0 ? n : DefaultSize;
	ch = new (std::nothrow)char[MaxSize+1];
	if (ch == nullptr)
	{
		exit(1);
	}
	strcpy(ch, other);
	CurLength = n;
}

Astring::Astring(const Astring& other)
{
	int len = other.Length();
	MaxSize = len > 0 ? len : MaxSize;
	ch = new(std::nothrow) char[MaxSize+1];
	if (ch == nullptr) { exit(1); }
	strcpy(ch, other.c_str());
	CurLength = len;
}

Astring& Astring::operator()(int pos, int len)
{

}

Astring & Astring::operator=(Astring& other)
{

}

int Astring::Find(Astring& other) const
{

}

char& Astring::operator[](int i) const
{

}
