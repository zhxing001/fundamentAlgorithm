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
		if (s == ' ')     //����ǿո�Ļ���˵��ǰ����һ�������ˣ�ѹ���ջ
		{
			st.push(tmp);
			tmp.clear();       //Ȼ���tmp���
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
	res += st.top();      //���һ����Ҫ�ո�
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


#include<vector>  
bool m[] = { false,true,false,true,false,true,false,true,true,false,true,false,true }; 
vector<string> b= { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };   
void weak(int year, int month, int day)
{
	//����·��Ƿ�Ϸ�
	if ((year <= 0 || month <= 0 || day <= 0) || (month == 2 && day > 29) || (!m[month] && day >= 31))     
	{
		printf("illegal\n");		    return;
	}
	//��������Ƿ�Ϸ�
	if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && day == 29)
	{
		printf("illegal\n");		    return;
	}


	if (month < 3)
	{
		year -= 1;
		month += 12;
	}
	//�����0001��1��1�յ�����һ�������죬Ȼ�����ȡ����
	int c = int(year / 100), y = year - 100 * c;
	int w = int(c / 4) - 2 * c + y + int(y / 4) + (26 * (month + 1) / 10) + day - 1;
	w = (w % 7 + 7+1) % 7;
	cout << b[w] << endl;
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
