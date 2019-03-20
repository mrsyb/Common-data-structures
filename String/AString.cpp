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
	strcpy(ch, other.ch);
	CurLength = len;
}

Astring& Astring::operator()(int pos, int len)
{
	Astring temp;
	if (pos < 0 || pos + len - 1 >= MaxSize || len <= 0)
	{
		temp.CurLength = 0;
		temp.ch[0] = '\0';
		return temp;
	}
	else
	{
		if (pos + len > CurLength)
			len = CurLength - pos;
		for (int i = 0; i < len; i++)
		{
			*temp.ch++ = ch[i + pos];
			i++;
		}
		temp.CurLength = len;
		temp.ch[len] = '\0';
	}
	
	return temp;
}

Astring & Astring::operator=(Astring& other)
{
	Astring temp;
	if (&other == this)
		return *this;
	delete[]ch;
	CurLength = other.CurLength;
	ch = new(std::nothrow) char[CurLength + 1];
	if (ch != nullptr)
	{
		while (*ch++ = *other.ch++ != '\0') {}
		ch[CurLength + 1] = '\0';
	}
	return  *this;
}

int Astring::Find(Astring& other, int k/*k=0*/) const
{
	int i, j;
	if (k + other.CurLength > CurLength)
		return -1;
	for (i = k; i < k + other.CurLength; i++)
	{
		for (j = 0; j < other.CurLength; j++)
		{
			if (ch[i+j] != other.ch[j])
			break;
		}
		if (j == other.CurLength)
			return i;
	}

	return -1;
}

int Astring::KMPFind(Astring & other)
{
	int i = 0; // 主串的位置
	int k = 0; // 模式串的位置
	int* next = new int[other.CurLength];
	GetNext(other,next);
	while (i < CurLength && k < other.CurLength) {

		if (k == -1 || ch[i] == other.ch[k]) { // 当j为-1时，要移动的是i，当然j也要归0
			i++;
			k++;
		}
		else {
			// i不需要回溯了
			// i = i - k + 1;
			k = next[k]; // j回到指定位置
		}
	}
	if (k == other.CurLength) {
		return i - k;
	}
	else {
		return -1;
	}

}


void Astring::GetNext(Astring& other, int* Next)const
{
	int j = 0 , k = -1;
	Next[0] = -1;
	while (j<other.CurLength)
	{
		if (k == -1 || other.ch[j] == other.ch[k])
		{
			j++; k++;
			Next[j] = k;
		}
		else
		{
			j = Next[k];
		}

	}
}

char& Astring::operator[](int i) const
{
	if (i < 0 || i >= CurLength)
	{
		exit(1);
	}
	return ch[i];
}
