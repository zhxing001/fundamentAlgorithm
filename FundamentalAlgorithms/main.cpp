//#include <iostream>
#include"RadixSort.h"
//#include<list>
//using namespace std;    //.h文件里已经包含这些了，这里可以不写

int main()
{

	//------------------【基数排序测试】--------------------
	int data[10] = {179,208,345,335,54,32,56,45,235,45};
	cout << "排序前：";
	for (int i = 0;i < 10;i++)
		cout << data[i] << " ";
	cout << endl;
	RadixSort(data, 10);
	cout << "排序前：";
	for (int i = 0;i < 10;i++)
		cout << data[i] << " ";
	cout << endl;
	//-----------------------end-----------------------------
	return 0;

}