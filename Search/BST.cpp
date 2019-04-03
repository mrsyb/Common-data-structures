#include "BST.h"

template<class T>
bool BST<T>::Remove(T x , BSTNode<T>* &ptr)
{/**思路，若删除的节点非叶子节点，则用中序序列的后续节点代替，
 递归删除替换节点。直至待删除的节点为叶子节点，真正删除。*/
	BSTNode<T>* temp;
	if (ptr != NULL)
	{
		if (x < ptr->Data) Remove(x, ptr->left);//从左子树删除
		else if (x > ptr->Data) Remove(x, ptr->right);//从有子树删除
		else if (ptr->left != NULL&& ptr->right != NULL)//找到了要删除的结点，且拥有左右孩子
		{
			temp = ptr->right;
			while (temp->left != NULL)//找到中序序列中的后续节点替换待删除的节点
				temp = temp->left;
			ptr->Data = temp->Data;
			Remove(ptr->Data, ptr->right);//从右子树中递归删除替换节点
		}
		else//找到了要删除的节点，且为叶子节点或者单一子节点
		{
			temp = ptr;
			if (ptr->left == NULL)//仅有右子树
				ptr = ptr->right;
			else//仅有左子树
				ptr = ptr->left;
			delete temp;//真正删除最终节点
			return true;
		}
	}
	return false;
}

template<class T>
BSTNode<T>* BST<T>::Min(BSTNode<T>* subTree)
{
	if (subTree->left == NULL)
		return subTree;
	Min(subTree->left);
}

template<class T>
BSTNode<T>* BST<T>::BinarySearch(T key, BSTNode<T>* ptr)
{
	if (ptr == NULL)
		return NULL;
	if (key > ptr->Data)
	{
		BinarySearch(ptr->right);
	}
	else if(key < ptr->Data)
	{
		BinarySearch(ptr->left);
	}
	else
	{
		return ptr;
	}
}

template<class T>
bool BST<T>::Insert(T e, BSTNode<T>* &x)
{
	if (x == NULL)
	{
		x = new T(e);
		return true;
	}
	else if(e < x->Data)
	{
		Insert(e, x->left);
	}
	else if(e > x->Data)
	{
		Insert(e, x->right);
	}
	else
	{
		return false;
	}

}


template<class T>
void BST<T>::MakeEmpty(BSTNode<T>& node)
{
	if (node.left != NULL&& node.right != NULL)
	{
		if (node.left != NULL)
		{
			MakeEmpty(node.left);
		}
		else if (node.right != NULL)
		{
			MakeEmpty(node.right);
		}
	}
	else {
		delete node;
	}
}


