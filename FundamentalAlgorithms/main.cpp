//#include <iostream>
#include"RadixSort.h"
//#include<list>
//using namespace std;    //.h�ļ����Ѿ�������Щ�ˣ�������Բ�д

int main()
{

	//------------------������������ԡ�--------------------
	int data[10] = {179,208,345,335,54,32,56,45,235,45};
	cout << "����ǰ��";
	for (int i = 0;i < 10;i++)
		cout << data[i] << " ";
	cout << endl;
	RadixSort(data, 10);
	cout << "����ǰ��";
	for (int i = 0;i < 10;i++)
		cout << data[i] << " ";
	cout << endl;
	//-----------------------end-----------------------------
	return 0;

}