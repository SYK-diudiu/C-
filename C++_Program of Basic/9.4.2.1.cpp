#include <iostream>
using namespace std;

int add(int x , int (*fun)(int , int))
{
	return fun(x , x);
}

int main()
{				  //�����б�           //��������       //������ 
	auto fun = []  (int a , int b)->     int        {return b*a*a;};
	cout << "fun(3,2): " << fun(3 , 2) << endl;
	cout << "add(5): " << add(5 , fun) << endl;
}
