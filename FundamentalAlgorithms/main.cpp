//#include <iostream>
#include"RadixSort.h"
//#include<list>
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