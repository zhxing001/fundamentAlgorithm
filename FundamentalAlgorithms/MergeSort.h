#pragma warning(disable:4996)
#pragma once
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include<algorithm>
//�鲢
//l�ǵ�һ���������㣬m�ǵ�һ������Ľ�β
template<class T>
void Merge(T *initList, T *mergeList, const int l, const int m, const int n)
{
	//����ǹ鲢�����������飬˫ָ��鲢
	int i1, i2;    //˫ָ��
	int index = l;    //���������������
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
	//������copy���ֻ��һ��������
	copy(initList + i1, initList + m + 1, mergeList + index);
	copy(initList + i2, initList + n + 1, mergeList + index);
}

template<class T>
void MergePass(T *initlist, T *result, int n, int s)   //n�����ݸ�����s��ÿ�θ���
{
	int i;
	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)    //����һ����n-2*s+1��ÿ����һ�ԣ����ɶԵĻ��Ͳ��ܱ����ˡ�
	{
		Merge(initlist, result, i, i + s - 1, i + 2 * s - 1);
	}
	if ((i + s - 1) < n)      //�������һ��merge�Ż�������ѭ����Ҳ����i=1������
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
		/*copy(tempList, tempList + n + 1, initlist); */   //ÿ�ζ�����һ�飬�����ظ�����
		//һ�ָ��õ�д��������������鲢һ�α任��ԭ�������飬�����Ǽ򵥵Ŀ�����Ч��Ҫ��һЩ
		l *= 2;
		MergePass(tempList, initlist, n, l);
	}
	delete[]  tempList;
}







#endif