//使用explicit关键字 
#include <iostream>
using namespace std;

class Box
{
	int length;
	public:
		/*explicit*/ Box(int len) : length(len) {	};
		void print(Box t);
};

void Box::print(Box t) //这里虽然参数列表写的是需要一个Box类的对象 
{					
	cout << "length: " << t.length << endl;
}

int main()
{
	Box a(2);
	a.print(5); //但是这里并没有传给函数Box对象，而是一个数字，但程序仍然可以运行
	//由于我们自定义了构造函数，编译器会在编译a.print(5)时把5转换为一个Box对象
	//编译器生成的代码为：a.print( Box {5} );
	//因此仍能输出length
	//在本程序中这种事情不会出问题，但是有些情况我们不希望编译器处理这种对函数不正当的用法
	//这时我们就需要在构造函数前面加上explicit关键字，不让它乱用 
}
