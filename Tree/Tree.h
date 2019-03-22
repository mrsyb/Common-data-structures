#pragma once
#include <cstdlib>
using namespace std;

template<class T>
struct BinaryNode 
{
	T Data;
	BinaryNode<T>* Left;
	BinaryNode<T>* Right;
	BinaryNode() :Left(NULL), Right(NULL) {}
	BinaryNode(T data, BinaryNode<T>* left = NULL, BinaryNode<T>* right = NULL) :Data(data), Left(left), Right(right) {}
};

