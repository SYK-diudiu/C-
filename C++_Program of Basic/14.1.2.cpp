//overrideʹ�÷������� 
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
		//����Ӳ���Ҳ�Ա�������û��Ӱ�� 
		/*virtual*/ void VoLuME() override;
/*
1��ע�⵽�������ǵ�volume�������Ѿ���Ŀȫ�ǣ� 
�ں����Ĳ����б���������override���ٴ�����ʱ����ֱ���
[Error] 'void Son::VoLuME()' marked override, but does not override 
��������˵�����ǰ�VoLuME�������Ϊ�˻��ຯ������д�����ǲ�û����д 
��ʵ�൱�ڱ��������Ǹ���һ���£����ǿ����ǵ�������������ڻ������Ƿ��ҵõ����Ҳ����Ļ�������д�����ֿ϶�����
����������Ҫ��VoLuME��Ϊvolume��ô�������Ϳ���ƥ�䵽����Box���ù����麯�������ǵ�volume�Ķ�̬�������ʵ��
2������û��дoverride�����ǵĳ��򲻻ᱨ������ִ�еĽ������ȷ
û��override�Ļ����൱��ʧȥ�˼����ƣ����ǵ�VoLuME�ᱻ��Ϊ����ĳ������
��Ȼ����֪�����ǵ���˼һ�������Ƕ��ڱ�������˵������get��
������������ΪVoLuME�ǻ�����volume����д
������main�����У���pָ��sonʱ��ʹ�õĺ�����Ȼ�ǻ���ĺ�������ʱ�������Ϊ��̬�󶨣��������Ϊpû�б��ѡ��
��ֻ���û����volume
3����͸������ǣ���������Ҫ�Ի����һ���麯�����и���ʱ����ü���override�Ժ������м�飬��Ϊͨ�����ִ�����ѱ����� 
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
