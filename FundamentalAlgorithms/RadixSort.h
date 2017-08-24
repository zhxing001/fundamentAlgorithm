#pragma once

//基数排序
#ifndef  RadxiSort


#include<iostream>
#include<list>
using namespace std;
//命名空间不能少，一开始编译不通过 list 存在问题，后来发现list是std::list  所以一定要写这个

int maxdigit(int data[], int n);

void RadixSort(int data[],int n)
{
	int digits = maxdigit(data, n);
	
	list<int> lists[10];   //十个链表，分别对应0.1.。。。9一共十位
	
	
	
	int factor = 1;
	for (int i = 0;i < digits;i++)
	{
		
		for (int j = 0;j < n;j++)
		{
			lists[(data[j] / factor) % factor].push_back(data[j]);
			//利用除法和取余运算可以算出每一位的个数。
		}
		for (int k = 0,j=0;j < 10;j++)
		{
			while (!lists[j].empty())
			{
				data[k] = lists[j].front();   //取出链表的数
				k++;
				lists[j].pop_front();     //取一个数删除一个节点。先放的先取
			}
		}
		factor *= 10;
	}

}



int maxdigit(int data[], int n)      //判断数组里最大的数是几位
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