//�����Ӿ��﷨ 
#include <iostream>
using namespace std;

int main()
{
	{
		int num = 5;
		// [=] ��ʾ���Բ���lambda���ʽ���ڴ��������б��� 
		auto fun = [=] ()->int{return num*num;};
		cout << fun() << endl;
	}
//		auto fun = [=] ()->int{return num*num;};	�ô��벻����д�����λ�ã���Ϊ�˴������û��num 
	{
		int a = 3; 
		int b = 3;
		cout << "b: " << b << endl;
		auto f = [=] ()mutable ->int{return b+=10;}; 
		int c = f();
		cout << "b: " << b << endl;
		cout << "c: " << c << endl;
		auto fun = [&b] () ->int{return b+=10;}; 
		fun();
		cout << "b: " << b << endl;
	}
}
