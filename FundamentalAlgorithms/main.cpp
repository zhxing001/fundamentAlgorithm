//#include <iostream>

#pragma warning(disable:4996)
#include"RadixSort.h"
//#include<list>

//using namespace std;    //.h�ļ����Ѿ�������Щ�ˣ�������Բ�д
#include<vector>


int Binary_Search1(vector<int> &v, int key);     //����Ŀ��
int Binary_Search2(vector<int> &v, int key);     //�������һ��С��Ŀ�����
int Binary_Search3(vector<int> &v, int key);     //���ҵ�һ�����ڵ���Ŀ�����

int Binary_Search4(vector<int> &v, int key);      //��һ������Ŀ�����
int Binary_Search5(vector<int> &v, int key);	  //���һ��С�ڵ���Ŀ�����
//int main()
//{
//
//	//------------------������������ԡ�--------------------
//	int data[10] = { 179,208,345,335,54,32,56,45,235,45 };
//	vector<int> v = { 1,2,3,4,5,8,9,10 };
//	cout << "Ŀ������:\t" << Binary_Search1(v, 3) << endl;
//	cout << "���һ��С��Ŀ�����������\t" << Binary_Search2(v, 3) << endl;
//	cout << "��һ�����ڵ���Ŀ�����������\t" << Binary_Search3(v, 3) << endl;
//	cout << "��һ������Ŀ�����������\t" << Binary_Search4(v, 3) << endl;
//	cout << "���һ��С�ڵ���Ŀ�����������\t" << Binary_Search5(v, 3) << endl;
//
//}

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

//merge�����������Ǻϲ������������䣬�������ǰ�����д����
// init��ԭ���飬tmp��Ŀ�����飬l�������㣬r���ұ���㣬re���ұ��յ�
void merge(int init[], int tmp[], int l, int r, int re)
{
	int le = r - 1;   //������յ�
	int tmp_index = l;\
	//˫ָ��鲢
	while (l <= le&&r <= re)
	{
		if (init[l] < init[r])  tmp[tmp_index++] = init[l++];
		else                    tmp[tmp_index++] = init[r++];
	}
	//���ȿ��ܲ��ȣ����Կ���û�й鲢�꣬���ﴦ��ʣ�µģ����������Ƕ�����һ�������
	while (l <= le)  tmp[tmp_index++] = init[l++];
	while (r <= re)  tmp[tmp_index++] = init[r++];
}


//һ�ι鲢���ֱ���Ҫ�������飬һ���鲢�ĳ��ȣ�һ������ĳ���
void mergePass(int init[], int tmp[], int length,int num)   //�����num�����ֵĸ�������Ҫ������������һ����
{
	int i=0;
	for (i = 0; i <= num - 2 * length; i += 2 * length)   
	{
		merge(init, tmp, i, i + length, i + 2 * length - 1);   //�������merge������
	}
	if (i + length < num)   //������滹��һ�����ϣ���������
	{
		merge(init, tmp, i, i + length, num - 1);    //��������β�һ�����Ĺ鲢
	}
	else    //�����������ʣ�µĲ���һ��length�ˣ���ôֱ�Ӹ���������
		while (i < num)
		{
			tmp[i++] = init[i++];
		}
}

void MergeSort(int init[], int num)
{
	int *tmp = new int[num];
	int length = 1;
	while (length<num)
	{
		mergePass(init, tmp, length, num);
		length *= 2;
		mergePass(tmp, init, length, num);
		length *= 2;
	}
	delete[] tmp;
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



int main()
{
	int s[] = { 1,2,3,4,3,5,4,5,6,7,86,5,4,3,3,2,4 };
	MergeSort(s, 17);
	for (auto ss : s)
		cout << ss << " ";
	cout << endl;
	return 0;
}





int GetNumberOfK(vector<int> data, int k) {
	int sz = data.size();
	if (sz == 0)  return 0;
	int left = 0;
	int right = sz - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (data[mid] >= k)
			right = mid - 1;
		else
			left = mid + 1;
	}

	int cnt = 0;
	for (int i = left; i < sz; i++)
	{
		if (data[i] == k)
			cnt++;
		else
			break;
	}
	return cnt;
}