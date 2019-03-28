#include "HuffmanTree.h"

template<class T>
HuffmanTree<T>::HuffmanTree(float w[], int n)
{
	MinHeap<T> Heap;
	HuffmanNode<T>* patent, first, second, work;

	for (int i = 0; i < n; i++)
	{
		work.data = w[i];
		work.leftChild = NULL;
		work.rightChild = NULL;
		work.parent = NULL;
		Heap.Insert(work);
	}
	for (int i = 0; i < n - 1; i++)
	{
		Heap.RemoveMin(first);
		Heap.RemoveMin(second);
		mergeTree(first, second, patent);
		Heap.Insert(patent);
	}
	Root = patent;
}

template<class T>
void HuffmanTree<T>::deleteTree(HuffmanNode<T>* t)
{
	if (t->leftChild != NULL && t->rightChild == NULL)
	{
		delete t;
	}
	deleteTree(t->leftChild);
	deleteTree(t->rightChild);
}

template<class T>
void HuffmanTree<T>::mergeTree(HuffmanNode<T>& ht1, HuffmanNode<T>& ht2, HuffmanNode<T>* &parent)
{
	parent = new HuffmanNode<T>;
	parent->leftChild = &ht1;
	parent->rightChild = &ht2;
	parent->data = ht1.data + ht2.data;
	ht1.parent = ht2.parent = parent;
}




