#include <iostream>
using namespace std;

int value1 = 1;

int main()
{
	int value1 = 2;
	
	//�˴���ʾ���ڲ�����������ȫ�ֱ���������
	//ȫ�ֱ���value1��main�����еľֲ�����value1ͬ��
	//�����������������������::���Ļ�������������ֲ�������ֵ 
	cout << "value1: " << /*���������������������Ҫ*/::value1 << endl;
	cout << "value1: " << value1 << endl;
} 
