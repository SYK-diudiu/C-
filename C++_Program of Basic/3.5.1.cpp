#include <iostream>
using namespace std;

int value1 = 1;

int main()
{
	int value1 = 2;
	
	//此处演示了内部变量会隐藏全局变量的特性
	//全局变量value1和main函数中的局部变量value1同名
	//如果不加作用域解析运算符“::”的话编译器会输出局部变量的值 
	cout << "value1: " << /*这个作用域解析运算符很重要*/::value1 << endl;
	cout << "value1: " << value1 << endl;
} 
