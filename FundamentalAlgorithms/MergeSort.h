#pragma warning(disable:4996)
#pragma once
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include<algorithm>
//归并
//l是第一个数组的起点，m是第一个数组的结尾
template<class T>
void Merge(T *initList, T *mergeList, const int l, const int m, const int n)
{
	//这个是归并两个排序数组，双指针归并
	int i1, i2;    //双指针
	int index = l;    //这个是新数组的序号
	for (i1 = l, i2 = m + 1; i1 <= m&&i2 <=n; index++)
	{
		if (initList[i1] < initList[i2])
		{
			mergeList[index] = initList[i1];
			i1++;
		}
		else 
		{
			mergeList[index] = initList[i2];
			i2++;
		}
	}
	//这两个copy最多只有一个起作用
	copy(initList + i1, initList + m + 1, mergeList + index);
	copy(initList + i2, initList + n + 1, mergeList + index);
}

template<class T>
void MergePass(T *initlist, T *result, int n, int s)   //n是数据个数，s是每段个数
{
	int i;
	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)    //这里一定是n-2*s+1，每两个一对，不成对的话就不能遍历了。
	{
		Merge(initlist, result, i, i + s - 1, i + 2 * s - 1);
	}
	if ((i + s - 1) < n)      //这是最后一次merge才会进入这个循环，也就是i=1下来的
	{
		Merge(initlist, result, i, i + s - 1, n);
	}
	else
	{
		cout << "i---  " << i << endl;
		copy(initlist + i, initlist + n + 1, result + i);
	}
}


template<class T>
void MergeSort(T *initlist, int n)
{
	T *tempList = new T[n + 1];
	for (int l = 1; l < n; l *= 2)
	{
		MergePass(initlist, tempList, n, l);	
		/*copy(tempList, tempList + n + 1, initlist); */   //每次都拷贝一遍，可以重复利用
		//一种更好的写法是下面这个，归并一次变换到原来的数组，而不是简单的拷贝，效率要高一些
		l *= 2;
		MergePass(tempList, initlist, n, l);
	}
	delete[]  tempList;
}







#endif