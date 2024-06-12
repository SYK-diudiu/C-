//命名空间相关功能的使用
 
#include <iostream>
using std::cout;
using std::endl;
namespace AAA
{
	void print(int a);
}
using AAA::print;

void AAA::print(int a)
{
	cout << "a: " << a << endl;
}
namespace A = AAA;
int main()
{
	int num = 10;
	AAA::print(num);	
	A::print(num);
	print(num);
}
