#include<string>
#include<iostream>
#include<vector>
using namespace std;



bool isDNA(char &x)
{
	if (x == 'A' || x == 'T' || x == 'C' || x == 'G')
		return true;
	else
		return false;
}

int LongestDna(string &s)
{
	int cnt = 0;
	int max = 0;
	for (auto ss : s)
	{
		if (isDNA(ss))
			cnt++;
		else
		{
			if (cnt>max)
				max = cnt;	
			cnt = 0;
		}
	}
	if (cnt>max)
		max = cnt;
	return max;
}

//这是一中分治法，这是在寻找最大值和最小值比较次数最小的方法。
template<class T>
bool MaxAndMinIndex(vector<T> v, int &maxIndex, int &minIndex)
{
	if (v.empty())
		return false;
	if (v.size() == 1)
		maxIndex = minIndex = 0;
	int s = 0;
	if (v.size() % 2 == 1)
	{
		maxIndex = 0;
		minIndex = 0;
	}
	else
	{
		if (v[0] < v[1])
		{
			minIndex = 0;
			maxIndex = 1;
		}
		else
		{
			minIndex = 1;
			maxIndex = 0;
		}
	}
	
	for (s = 2; s < v.size(); s+=2)
	{
		if (v[s] < v[s + 1])
		{
			if (v[s] < v[minIndex])
				minIndex = s;
			if (v[s + 1] > v[maxIndex])
				maxIndex = s + 1;
		}
		else
		{
			if (v[s] > v[maxIndex])
				maxIndex = s;
			if (v[s + 1] < v[minIndex])
				minIndex = s + 1;
		}
	}
	return true;

}

int main()
{
	
	vector<int> v1 = { 1,2,3,4,5,6,7,8 ,4,5,5,6,75,53,3,6,5,34};
	int minIndex, maxIndex;
	MaxAndMinIndex(v1, maxIndex, minIndex);
	cout << "maxIndex:\t " << maxIndex << "\tmaxValue:" << v1[maxIndex] << endl;
	cout << "minIndex:\t" << minIndex << "\tminValue" << v1[minIndex] << endl;
	cout << *v1.begin() << endl;
	cout << *v1.rbegin() << endl;
	cout << v1.back() << endl;

	string ss = "ABCBOATER";
	cout << LongestDna(ss) << endl;

	
	
	return 0;

}