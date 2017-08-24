#pragma once

//��������
#ifndef  RadxiSort


#include<iostream>
#include<list>
using namespace std;
//�����ռ䲻���٣�һ��ʼ���벻ͨ�� list �������⣬��������list��std::list  ����һ��Ҫд���

int maxdigit(int data[], int n);

void RadixSort(int data[],int n)
{
	int digits = maxdigit(data, n);
	
	list<int> lists[10];   //ʮ�������ֱ��Ӧ0.1.������9һ��ʮλ
	
	
	
	int factor = 1;
	for (int i = 0;i < digits;i++)
	{
		
		for (int j = 0;j < n;j++)
		{
			lists[(data[j] / factor) % factor].push_back(data[j]);
			//���ó�����ȡ������������ÿһλ�ĸ�����
		}
		for (int k = 0,j=0;j < 10;j++)
		{
			while (!lists[j].empty())
			{
				data[k] = lists[j].front();   //ȡ���������
				k++;
				lists[j].pop_front();     //ȡһ����ɾ��һ���ڵ㡣�ȷŵ���ȡ
			}
		}
		factor *= 10;
	}

}



int maxdigit(int data[], int n)      //�ж��������������Ǽ�λ
{
	int d = 1;
	int p = 10;
	for (int i = 0;i < n;i++)
	{
		while (data[i] >= p)
		{
			p *= 10;
			d++;
		}
	}
	return d;
}

#endif 