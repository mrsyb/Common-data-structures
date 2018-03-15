/*直接插入排序
算法思想：每次将一个待排序的序列按照关键字大小插入到前面已经排好序的序列中。
空间复杂度：O（1）
时间复杂度：最好（已经排好序）为O（n）
			最差（完全逆序）为O（n^2）
			平均O（n^2）
算法稳定情况：稳定
适用性：适用于顺序存储和链式存储
============================================================================
插入排序都进行了两次操作1>（查找，顺序查找O（n））从已排序序列中查找到应该插入的位置
						2>（插入，顺序存储的线性表的插入）给待插入元素腾出空间，将大于待插入元素的元素向后挪
============================================================================
折半插入排序（将直接插入算法的查找过程改进，使用折半查找O（logn））
算法思想：每次将一个待排序的序列按照关键字大小插入到前面已经排好序的序列中。
空间复杂度：O（1）
时间复杂度：查找部分由O（n）-->O(logn),插入部分没有改变仍为O（n^2）,,所以平均仍为O（n^2）
算法稳定情况：稳定
*/
#include "dataList.h"

template <class T>
void InsertSort(dataList<T> &L,const int left, const int right) {
	//依次将元素L.Vector[left]按其排序码依次插入到有序表L.Vector[left],...,L.Vector[i-1]
	//中，使得L.Vector[left]...Vector[i]有序
	Element<T> temp; int i, j;
	for (i = left + 1; i < = right; i++){
		if (L[i] < L[i - 1]){
			temp = L[i];
			j = i - 1;
			do {
				L[j + 1] = L[j];
				j--;
			} while (j > left && temp < L[j])
			L[j + 1] = temp;
		}
	}
};

template <class T>
viod BinaryInsertSort(dataList<T> &L, const int left, const int right){
	Element<T> temp;
	int i, j, low, mid, hight;
	for (i = left + 1; i <= right; i++){
		temp = L[i];
		low = left;
		hight = i - 1;
		while (low <= hight) {
			mid = (hight + low) / 2;
			if (temp < L[mid])
				hight = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= low; j--)
			L[j + 1] = L[j];
		L[low] = temp;
	}
};