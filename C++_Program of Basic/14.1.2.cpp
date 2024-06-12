//override使用方法介绍 
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
		//这里加不加也对本节内容没有影响 
		/*virtual*/ void VoLuME() override;
/*
1、注意到这里我们的volume函数名已经面目全非， 
在函数的参数列表后面加上了override，再次运行时会出现报错：
[Error] 'void Son::VoLuME()' marked override, but does not override 
上述报错说，我们把VoLuME函数标记为了基类函数的重写，但是并没有重写 
其实相当于编译器就是干了一个事，就是看你标记的这个函数名，在基类中是否找得到，找不到的话那你重写的名字肯定错了
所以我们需要把VoLuME改为volume那么编译器就可以匹配到基类Box设置过的虚函数，我们的volume的动态绑定则可以实现
2、假设没有写override，我们的程序不会报错，但是执行的结果不正确
没有override的话，相当于失去了检查机制，我们的VoLuME会被视为另外某个函数
虽然我们知道它们的意思一样，但是对于编译器来说它不能get到
所以它不会认为VoLuME是基类中volume的重写
所以在main函数中，当p指向son时，使用的函数仍然是基类的函数，此时可以理解为静态绑定，或者理解为p没有别的选择
它只能用基类的volume
3、这就告诉我们，当我们需要对基类的一个虚函数进行更改时，最好加上override对函数进行检查，因为通常这种错误很难被发现 
*/ 
		Son(string material , int length = 0 , int width = 0 , int height = 0);
}; 

Son::Son(string material , int length , int width , int height)
:Box(length , width , height)
{
	_material = material;	
}

void Son::VoLuME()
{
	int v = _length*_width*_height*0.5;
	cout << "Son->volume: " << v << "\tmaterial: " << _material << endl;
}

int main()
{
	Box box(2,2,2);
	box.volume();
	Son son("plastic",2,2,2);
	son.volume();
//	Carton car("plastic",2,2,2,1);
//	car.volume();
	cout << endl;
	Box *p = NULL;
	p = &box;
	p->volume();
	p = &son;
	p->volume();
//	p = &car;
//	p->volume();
}
