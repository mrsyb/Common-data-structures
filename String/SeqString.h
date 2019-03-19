#pragma once
#include <cstdlib>

# define DefaultSize 256
typedef struct SeqString 
{
	char* ch;
	int MaxSize;
	int CurLength;
};

SeqString MyString;

void InitSeqString(SeqString s)
{
	s.ch = new (std::nothrow)char[DefaultSize];
	if (s.ch == nullptr)
	{
		exit(1);
	}
	s.ch[0] = '\0';
	s.MaxSize = DefaultSize;
	s.CurLength = 0;
}

void OverFlowProcess()
{
	char* NewAddress = new(std::nothrow) char[2 * MyString.MaxSize];
	if (NewAddress == nullptr)
	{
		exit(1);
	}
	int n = MyString.MaxSize = 2 * MyString.MaxSize;
	char* SrcPtr = MyString.ch;
	char* DestPtr = NewAddress;
	while (n--)
	{
		*DestPtr++ = *SrcPtr++;
	}
	delete[] MyString.ch;
	MyString.ch = NewAddress;
}

