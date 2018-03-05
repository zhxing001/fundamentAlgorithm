//#include <iostream>
#include"RadixSort.h"
//#include<list>
//using namespace std;    //.h文件里已经包含这些了，这里可以不写
#include<vector>


int Binary_Search1(vector<int> &v, int key);     //查找目标
int Binary_Search2(vector<int> &v, int key);     //查找最后一个小于目标的数
int Binary_Search3(vector<int> &v, int key);     //查找第一个大于等于目标的数

int Binary_Search4(vector<int> &v, int key);      //第一个大于目标的数
int Binary_Search5(vector<int> &v, int key);	  //最后一个小于等于目标的数
int main()
{

	//------------------【基数排序测试】--------------------
	int data[10] = {179,208,345,335,54,32,56,45,235,45};
	vector<int> v = { 4,5,8,9,10};
	cout <<"目标索引:\t"<< Binary_Search1(v, 3) << endl;
	cout <<"最后一个小于目标的数索引：\t" <<Binary_Search2(v, 3) << endl;
	cout <<"第一个大于等于目标的数索引：\t"<<Binary_Search3(v, 3) << endl;
	cout << "第一个大于目标的数索引：\t" << Binary_Search4(v, 3) << endl;
	cout << "最后一个小于等于目标的数索引：\t" << Binary_Search5(v, 3) << endl;
	


	/*cout << "排序前：";
	for (int i = 0;i < 10;i++)
		cout << data[i] << " ";
	cout << endl;
	RadixSort(data, 10);
	cout << "排序前：";
	for (int i = 0;i < 10;i++)
		cout << data[i] << " ";
	cout << endl;*/
	//-----------------------end-----------------------------
	return 0;

}

int Binary_Search1(vector<int> &v, int key)
{
	int left = 0;
	int right = v.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key > v[mid])
			left = mid + 1;
		else if (key < v[mid])
			right = mid - 1;
		else
		{
			return mid;      //找到的话返回下标
		}
	}
	return -1;    //表示没有找到
}





int Binary_Search2(vector<int> &v, int key)
{
	int left = 0;
	int right = v.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key > v[mid])
			left = mid + 1;
		else if (key <=v[mid])
			right = mid - 1;
		
	}
	return right;    
}


int Binary_Search3(vector<int> &v, int key)
{
	int left = 0;
	int right = v.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key > v[mid])
			left = mid + 1;
		else if (key <= v[mid])
			right = mid - 1;

	}
	return left;    
}

int Binary_Search4(vector<int> &v, int key)
{
	int left = 0;
	int right = v.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key >= v[mid])
			left = mid + 1;
		else if (key < v[mid])
			right = mid - 1;

	}
	return left;    
}

int Binary_Search5(vector<int> &v, int key)
{
	int left = 0;
	int right = v.size() - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key >= v[mid])
			left = mid + 1;
		else if (key < v[mid])
			right = mid - 1;

	}
	return right;    
}