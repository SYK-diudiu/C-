#include <iostream>
using namespace std;

int main()
{
	int array[3]{1 , 2 , 3}; //������Ϊ�˼�¼��������ֶ��岢��ʼ���ķ�ʽ 
/*���ߣ�int array[3] = {1 , 2 , 3};*/
//�����źͻ������м��ǿ���û�еȺŵģ���ʹ���ϵȺţ�����Ҳ������� 
	for(int i = 0 ; i < 3 ; ++i)
		cout << "array[" << i << "]-->" << array[i] << endl;
	cout << sizeof(array) << endl; //����ֵ����������ռ�õ����ֽ���������������ľ���12 
} 
