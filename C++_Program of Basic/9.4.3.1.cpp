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
{				  //参数列表           //返回类型       //函数体 
	auto fun = []  (int a , int b)->     int        {return b*a*a;};
	cout << "fun(3,2): " << fun(3 , 2) << endl;
	cout << "add(5): " << add(5 , fun) << endl;
	
	function<int(int)> p; //函数指针包装器，它等价于 int (*p)(int) 
	
	p = print;
	int ret = p(999);
	cout << "ret: " << ret << endl;
}
