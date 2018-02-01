//#include <iostream>

#pragma warning(disable:4996)
#include"RadixSort.h"
//#include<list>
using namespace std;    //.h文件里已经包含这些了，这里可以不写
#include"MergeSort.h"
int main()
{

	int a[] = { 0,1,3,5,7,9,2,4,6,8,10 };
	int b[11] = {0};
	Merge(a, b, 1, 5 , 10);
	for (int i = 0; i < 11; i++)
		cout << b[i] << " ";
	cout <<endl;
	int m[] = { 0,26,5,77,1,61,11,59,15,48,19};
	int n[12] = { 0 };
	MergePass(m, n, 10, 1);
	for (int i = 0; i < 11; i++)
		cout << n[i] << " ";
	cout << endl;

	MergePass(n, m, 10, 2);
	for (int i = 0; i < 11; i++)
		cout << m[i] << " ";
	cout << endl;


	MergePass(m, n, 10, 4);
	for (int i = 0; i < 11; i++)
		cout << n[i] << " ";
	cout << endl;

	MergePass(n, m, 10, 8);
	for (int i = 0; i < 11; i++)
		cout << m[i] << " ";
	cout << endl;


	////------------------【基数排序测试】--------------------
	//int data[10] = {179,208,345,335,54,32,56,45,235,45};
	//cout << "排序前：";
	//for (int i = 0;i < 10;i++)
	//	cout << data[i] << " ";
	//cout << endl;
	//RadixSort(data, 10);
	//cout << "排序前：";
	//for (int i = 0;i < 10;i++)
	//	cout << data[i] << " ";
	//cout << endl;
	////-----------------------end-----------------------------
	return 0;

}