//ί�й��캯�� 
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

Box::Box(int len , int hei , int wid) //��ί�еĺ��� 
: length(len) , height(hei) , width(wid)
{
	
}

Box::Box(int every) //ί�б��˵ĺ��� 
: Box(every , every , every) //ί�й��캯���÷� 
{
	
}

int main()
{
	Box a(1 , 2 , 3);
	a.print();
	Box b(5);
	b.print();
	
}
