#include <iostream>
using namespace std;

//介绍两种自定义类型的方式，一个老朋友一个新朋友 
typedef int NUM;
using num = int;

int main()
{
	num a{1};
	NUM b{2};
	cout << "a: " << a << endl;	
	cout << "b: " << b << endl;	
}
