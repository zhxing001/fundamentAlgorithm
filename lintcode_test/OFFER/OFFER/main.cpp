#include<iostream>
#include<string>
#include<stack>
#include<list>

using namespace std;

string ReverseSentence(string str) {
	if (str.empty())  return string();         //Handling special circumstances
	string tmp;              //temporary string
	stack<string>  st;        //stack
	for (auto s : str)
	{
		if (s == ' ')     //如果是空格的话，说明前面是一个单词了，压入堆栈
		{
			st.push(tmp);
			tmp.clear();       //然后把tmp清空
		}
		else
			tmp += s;
	}
	if (!tmp.empty())      //if tmp is not empty
		st.push(tmp);

	string res;
	while (st.size()>1)
	{
		res += st.top() + ' ';
		st.pop();
	}
	res += st.top();      //最后一个不要空格
	return res;
}

void swap(int *x, int *y)
{
	int *tmp=x;
	tmp = x;
	x = y;
	y = tmp;
}



int LastRemaining_Solution(int n, int m)
{
	list<int>  lor;
	for (int i = 0; i < n; i++)
	{
		lor.push_back(i);
	}
	if (lor.size() == 1)  return 0;
	else
	{
		while (lor.size() > 1)
		{
		    size_t tmp_sz =m%lor.size();
			list<int>::iterator tt;
			tt = lor.begin();
			for (int j = 0; j < tmp_sz; j++)
			{
				tt++;
			}
			lor.erase(tt);
		}
	}
	return *lor.begin();
}

int lcm(const int &l, const int &m)
{
	int i = 0;
	int min = l < m ? l : m;
	//
	for (i = l; i < l*m; i++)
	{
		if (i%l == 0 && i%m == 0)
			break;
	}
	return i;
}



	
int main()
{
	/*string m;
	cin >> m;
	int mp[256] = { 0 };
	for (int i = 0; i < m.size(); i++)
	{
		mp[m[i]]++;
	}
	int flag=0;
	for (char i = 'a'; i <= 'z'; i++)
	{
		if (mp[i] == 0)  
		{cout << i;
		flag++;
		}
	}
	if(flag==0)
	cout<<0;
	cout << endl;*/
	int y, m, d;
	while (cin >> y >> m >> d)
	{
		weak(y, -m, -d);
	}
		
	/*int a, b;
	while (cin >> a >> b)
		cout << lcm(a,b) << endl;*/


	//cout << lcm(2, 5) << endl;
	//cout << lcm(5, 20) << endl;
	//int x = 1;
	//int y = 2;
	//swap(&x, &y);
	//cout << x << " " << y << endl;

	return 0;

}

