/*冒泡排序的两种方法
  算法思想：从后往前两两比较，若为逆序V[i-1]>V[i]则交换次序，
            每趟都会把序列中最小的元素排列到最终位置
空间复杂度：O（1）
时间复杂度：最好（已经排好序）为O（n）
			最差（完全逆序）为O（n^2）
算法稳定情况：稳定
*/

#include "DataList.h"

template <class T>
void Sort<T>::BubbleSort1(DataList<T> &V, int n) {
	//对数组中n个元素进行冒泡排序，执行n-1趟，第i趟对地V[n-1]到V[i]起泡
#pragma region timing
	clock_t startTime, endTime;
	startTime = clock();//开始计时
#pragma endregion

	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--)
			if (V[j - 1] > V[j])
			{
				Element<T> temp = V[j - 1];
				V[j - 1] = V[j];
				V[j] = temp;
			}
	}
		
#pragma region print
	V.MyPrint(true);
	endTime = clock();//结束计时
	cout << "BubbleSort1 run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << 's' << endl;
#pragma endregion
}
template <class T>
void Sort<T>::BubbleSort2(DataList<T> &V, int n) {
#pragma region timing
	clock_t startTime, endTime;
	startTime = clock();//开始计时
#pragma endregion
	//设置交换标记exchange，如果本次冒泡没有发生交换，则说明排序完成，停止处理
	bool exchange;
	int i, j;
	
	for (i = 1; i < n; i++) {
		exchange = false;
		for (j = n - 1; j >= i; j--)
		{
			if (V[j - 1] > V[j])
			{
				Element<T> temp = V[j - 1];
				V[j - 1] = V[j];
				V[j] = temp;
				exchange = true;
			}
		}
		if (exchange == false)
		{
#pragma region Timing
			V.MyPrint(true);
			endTime = clock();//结束计时
			cout << "BubbleSort2 run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << 's' << endl;
#pragma endregion
			return;
		}
	}
#pragma region print
	V.MyPrint(true);
	endTime = clock();//结束计时
	cout << "BubbleSort2 run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << 's' << endl;
#pragma endregion

};

