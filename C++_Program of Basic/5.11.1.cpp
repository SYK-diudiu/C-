#include <iostream>
#include <array>
using namespace std;
/*
ʹ��array<T,N>���� 
*/
int main()
{
	//��ζ���
	array<int , 5> arr {1,2,3,4,5};
	
	cout << "first:" << endl;
	for(int x : arr)
	{
		cout << "x--->" << x << endl;
	}
	
	cout << "second:" << endl;
	arr.fill(9); //�˳�Ա�������԰����������е�ֵ����Ϊ�����е�ֵ 
	for(int x : arr)
	{
		cout << "x--->" << x << endl;
	}
}
