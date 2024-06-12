//捕获子句语法 
#include <iostream>
using namespace std;

int main()
{
	{
		int num = 5;
		// [=] 表示可以捕获lambda表达式所在代码块的所有变量 
		auto fun = [=] ()->int{return num*num;};
		cout << fun() << endl;
	}
//		auto fun = [=] ()->int{return num*num;};	该代码不可以写在这个位置，因为此代码块中没有num 
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
