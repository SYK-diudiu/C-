#include <iostream>
#include <functional>
using namespace std;

int add(int x , function<int(int , int)> fun)
{
	return fun(x , x);
}

int print(int a)
{
	cout << "print: " << a << endl;
	return a;
}

int main()
{				  //�����б�           //��������       //������ 
	auto fun = []  (int a , int b)->     int        {return b*a*a;};
	cout << "fun(3,2): " << fun(3 , 2) << endl;
	cout << "add(5): " << add(5 , fun) << endl;
	
	function<int(int)> p; //����ָ���װ�������ȼ��� int (*p)(int) 
	
	p = print;
	int ret = p(999);
	cout << "ret: " << ret << endl;
}
