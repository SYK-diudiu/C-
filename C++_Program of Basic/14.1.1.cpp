//�麯�������ú�ʹ�� 
#include <iostream>
using namespace std;

//����Box 
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

//Box������
class Son : public Box //����ļ̳з�ʽ����дΪprotected����������private������ᱨ�� 
{						  //[Error] 'Box' is an inaccessible base of 'Son' 
	protected:
		string _material;
	public:
		/*virtual*/ void volume();
/*
�˴��Ӳ���virtual��Ч����һ������Ϊ�����ͬ�������Ѿ�����Ϊ�麯��
��ô֮������ֱ�ӻ����������ͬ������������ʵ�ֶ�̬�� 
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

//Son�������� 
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
