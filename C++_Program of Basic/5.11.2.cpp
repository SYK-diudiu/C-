#include <iostream>
#include <vector>
using namespace std;
/*
ʹ��vector<T>���� 
*/
int main()
{
	vector<int> vec(5 , 2); //����vector<int> vec {2,2,2,2,2} ������ʸ�������Ĵ�����ʽ��������������� 
	int total = 0;			//�������������ŷ���������ͬ 
	for(int i = 0 ; i <= vec.size() ; ++i)
	{
		total += vec.at(i);
	}
	cout << total << endl;
}
/*
ע�⣺������ᱨ����Ϊ��i = vec.size()ʱ
������at()���⵽i��ֵ�Ѿ�����Ԫ�ظ������ֵ��������1
���к����������ʾ������г������±��� 
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 5) >= this->size() (which is 5) 
*/
