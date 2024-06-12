//虚函数的设置和使用 
#include <iostream>
using namespace std;

//基类Box 
class Box
{
	protected:
		int _length;
		int _width;
		int _height;
	public:
		virtual void volume();	
		Box(int length = 0 , int width = 0 , int height = 0);
};

Box::Box(int length , int width , int height)
{
	_length = length;
	_width = width;
	_height = height;
}

void Box::volume()
{
	int v = _length*_width*_height;
	cout << "Box->volume: " << v << endl;
}

//Box派生类
class Son : public Box //这里的继承方式不能写为protected，更不能是private，否则会报错 
{						  //[Error] 'Box' is an inaccessible base of 'Son' 
	protected:
		string _material;
	public:
		/*virtual*/ void volume();
/*
此处加不加virtual，效果都一样，因为基类的同名函数已经设置为虚函数
那么之后基类的直接或间接派生类的同名函数都将会实现动态绑定 
*/
		Son(string material , int length = 0 , int width = 0 , int height = 0);
}; 

Son::Son(string material , int length , int width , int height)
:Box(length , width , height)
{
	_material = material;	
}

void Son::volume()
{
	int v = _length*_width*_height*0.5;
	cout << "Son->volume: " << v << "\tmaterial: " << _material << endl;
}

//Son的派生类 
class Carton : public Son
{
	protected:
		int _border;
	public:
		void volume(); 
		Carton(string material , int length = 0 , int width = 0 , int height = 0 , int border = 0);
};

void Carton::volume()
{
	int v = _length*_width*_height*0.25;
	cout << "Carton->volume: " << v << "\tmaterial: " << _material << "\tborder: " << _border << endl;
}

Carton::Carton(string material , int length , int width , int height , int border)
:Son(material , length , width , height)
{
	_border = border;
}

int main()
{
	Box box(2,2,2);
	box.volume();
	Son son("plastic",2,2,2);
	son.volume();
	Carton car("plastic",2,2,2,1);
	car.volume();
	cout << endl;
	Box *p = NULL;
	p = &box;
	p->volume();
	p = &son;
	p->volume();
	p = &car;
	p->volume();
}
