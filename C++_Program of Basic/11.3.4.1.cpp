//ʹ��explicit�ؼ��� 
#include <iostream>
using namespace std;

class Box
{
	int length;
	public:
		/*explicit*/ Box(int len) : length(len) {	};
		void print(Box t);
};

void Box::print(Box t) //������Ȼ�����б�д������Ҫһ��Box��Ķ��� 
{					
	cout << "length: " << t.length << endl;
}

int main()
{
	Box a(2);
	a.print(5); //�������ﲢû�д�������Box���󣬶���һ�����֣���������Ȼ��������
	//���������Զ����˹��캯�������������ڱ���a.print(5)ʱ��5ת��Ϊһ��Box����
	//���������ɵĴ���Ϊ��a.print( Box {5} );
	//����������length
	//�ڱ��������������鲻������⣬������Щ������ǲ�ϣ���������������ֶԺ������������÷�
	//��ʱ���Ǿ���Ҫ�ڹ��캯��ǰ�����explicit�ؼ��֣����������� 
}
