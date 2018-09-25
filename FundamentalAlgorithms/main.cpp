//#include <iostream>

#pragma warning(disable:4996)
#include"RadixSort.h"
//#include<list>

//using namespace std;    //.h文件里已经包含这些了，这里可以不写
#include<vector>


int Binary_Search1(vector<int> &v, int key);     //查找目标
int Binary_Search2(vector<int> &v, int key);     //查找最后一个小于目标的数
int Binary_Search3(vector<int> &v, int key);     //查找第一个大于等于目标的数

int Binary_Search4(vector<int> &v, int key);      //第一个大于目标的数
int Binary_Search5(vector<int> &v, int key);	  //最后一个小于等于目标的数
//int main()
//{
//
//	//------------------【基数排序测试】--------------------
//	int data[10] = { 179,208,345,335,54,32,56,45,235,45 };
//	vector<int> v = { 1,2,3,4,5,8,9,10 };
//	cout << "目标索引:\t" << Binary_Search1(v, 3) << endl;
//	cout << "最后一个小于目标的数索引：\t" << Binary_Search2(v, 3) << endl;
//	cout << "第一个大于等于目标的数索引：\t" << Binary_Search3(v, 3) << endl;
//	cout << "第一个大于目标的数索引：\t" << Binary_Search4(v, 3) << endl;
//	cout << "最后一个小于等于目标的数索引：\t" << Binary_Search5(v, 3) << endl;
//
//}

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

//merge函数，这里是合并两个排序区间，所以我们把这里写出来
// init是原数组，tmp是目标数组，l是左边起点，r是右边起点，re是右边终点
void merge(int init[], int tmp[], int l, int r, int re)
{
	int le = r - 1;   //算左边终点
	int tmp_index = l;\
	//双指针归并
	while (l <= le&&r <= re)
	{
		if (init[l] < init[r])  tmp[tmp_index++] = init[l++];
		else                    tmp[tmp_index++] = init[r++];
	}
	//长度可能不等，所以可能没有归并完，这里处理剩下的，这里做的是对任意一个数组的
	while (l <= le)  tmp[tmp_index++] = init[l++];
	while (r <= re)  tmp[tmp_index++] = init[r++];
}


//一次归并，分别需要两个数组，一个归并的长度，一个数组的长度
void mergePass(int init[], int tmp[], int length,int num)   //这里的num是数字的个数，是要比最后的索引多一个的
{
	int i=0;
	for (i = 0; i <= num - 2 * length; i += 2 * length)   
	{
		merge(init, tmp, i, i + length, i + 2 * length - 1);   //这里就算merge结束了
	}
	if (i + length < num)   //如果后面还有一段以上，不够两段
	{
		merge(init, tmp, i, i + length, num - 1);    //把最后两段不一样长的归并
	}
	else    //这种情况下面剩下的不够一段length了，那么直接复制下来。
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