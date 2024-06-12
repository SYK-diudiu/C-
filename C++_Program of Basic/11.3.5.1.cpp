//委托构造函数 
#include <iostream>
using namespace std;

class Box
{
	int length;
	int height;
	int width;
	public:
		Box(int len , int hei , int wid);
		Box(int every);
		void print();
};

void Box::print()
{
	cout << "Volume: " << length*width*height << endl;
}

Box::Box(int len , int hei , int wid) //被委托的函数 
: length(len) , height(hei) , width(wid)
{
	
}

Box::Box(int every) //委托别人的函数 
: Box(every , every , every) //委托构造函数用法 
{
	
}

int main()
{
	Box a(1 , 2 , 3);
	a.print();
	Box b(5);
	b.print();
	
}
