#pragma once

template<class T>
void InsertSort(T *a, int n)
{
	int i, j;
	for (j = 1; j < n; j++)
	{
		int tmp = a[j];
		cout << "tmp:" << tmp << endl;
		i = j-1;     //ÒÑÅÅÐòµÄ
		while (i >= 0)
		{
			
			if (tmp < a[i])
			{
				a[i + 1] = a[i];
				i--;
			}
			else
			{
				a[i+1] = tmp;
				break;
			}
		}
	}
}
