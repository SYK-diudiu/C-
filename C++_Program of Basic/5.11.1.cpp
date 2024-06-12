#include <iostream>
#include <array>
using namespace std;
/*
使用array<T,N>容器 
*/
int main()
{
	//如何定义
	array<int , 5> arr {1,2,3,4,5};
	
	cout << "first:" << endl;
	for(int x : arr)
	{
		cout << "x--->" << x << endl;
	}
	
	cout << "second:" << endl;
	arr.fill(9); //此成员函数可以把容器中所有的值设置为括号中的值 
	for(int x : arr)
	{
		cout << "x--->" << x << endl;
	}
}
