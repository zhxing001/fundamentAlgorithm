//#include <iostream>

#pragma warning(disable:4996)
#include"RadixSort.h"
//#include<list>
<<<<<<< HEAD
//using namespace std;    //.h�ļ����Ѿ�������Щ�ˣ�������Բ�д
#include<vector>


int Binary_Search1(vector<int> &v, int key);     //����Ŀ��
int Binary_Search2(vector<int> &v, int key);     //�������һ��С��Ŀ�����
int Binary_Search3(vector<int> &v, int key);     //���ҵ�һ�����ڵ���Ŀ�����

int Binary_Search4(vector<int> &v, int key);      //��һ������Ŀ�����
int Binary_Search5(vector<int> &v, int key);	  //���һ��С�ڵ���Ŀ�����
int main()
{

	//------------------������������ԡ�--------------------
	int data[10] = {179,208,345,335,54,32,56,45,235,45};
	vector<int> v = { 4,5,8,9,10};
	cout <<"Ŀ������:\t"<< Binary_Search1(v, 3) << endl;
	cout <<"���һ��С��Ŀ�����������\t" <<Binary_Search2(v, 3) << endl;
	cout <<"��һ�����ڵ���Ŀ�����������\t"<<Binary_Search3(v, 3) << endl;
	cout << "��һ������Ŀ�����������\t" << Binary_Search4(v, 3) << endl;
	cout << "���һ��С�ڵ���Ŀ�����������\t" << Binary_Search5(v, 3) << endl;
	


	/*cout << "����ǰ��";
	for (int i = 0;i < 10;i++)
		cout << data[i] << " ";
	cout << endl;
	RadixSort(data, 10);
	cout << "����ǰ��";
	for (int i = 0;i < 10;i++)
		cout << data[i] << " ";
	cout << endl;*/
	//-----------------------end-----------------------------
=======
using namespace std;    //.h�ļ����Ѿ�������Щ�ˣ�������Բ�д
#include"MergeSort.h"
#include"InsertSort.h"
int main()
{

	int a[] = { 0,1,3,5,56,6,768,87,6,6745,7,9,2,4,6,8,10 };
	InsertSort(a, 17);
	for (int i = 0; i < 17; i++)
		cout << a[i] << " ";


	/*int b[11] = {0};
	Merge(a, b, 1, 5 , 10);
	for (int i = 0; i < 11; i++)
		cout << b[i] << " ";
	cout <<endl;
	int m[] = { 0,26,5,77,1};
	int n[12] = { 0 };
	
	MergeSort(m, 4);
	for (int i = 0; i < 5; i++)
		cout << m[i] << " ";
	cout << endl;
*/
	////------------------������������ԡ�--------------------
	//int data[10] = {179,208,345,335,54,32,56,45,235,45};
	//cout << "����ǰ��";
	//for (int i = 0;i < 10;i++)
	//	cout << data[i] << " ";
	//cout << endl;
	//RadixSort(data, 10);
	//cout << "����ǰ��";
	//for (int i = 0;i < 10;i++)
	//	cout << data[i] << " ";
	//cout << endl;
	////-----------------------end-----------------------------
>>>>>>> f1521402d4bd8453d839a881d90d2f9b3c6d53f7
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
			return mid;      //�ҵ��Ļ������±�
		}
	}
	return -1;    //��ʾû���ҵ�
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