#include <iostream>
using namespace std;

//ö������Ĭ����int���� 
enum class Day
{
	Monday = 1 , Tuesday , Wednesday , Thursday , Friday = 9 , Saturday = Monday + 1 , Sunday 
};

//ö�����Ϳ������ó�ֵΪchar���ͣ���ʵ�Ͽ�����Ĭ��int����֮����������ͣ���ֻ��char������string������ 
enum class S
{
	str1 = 'a' , str2 = 'b' 
};

int main()
{
	//��ϰʹ��enum�� ͬʱ ��ʾ���ָ�ֵ���� 
	Day d1 = Day::Monday; 
	Day d2 {Day::Friday};
	Day d3 = {Day::Sunday};
	cout << "Today is " << static_cast<int>(d1) << endl;
	cout << "Today is " << static_cast<int>(d2) << endl;
	cout << "Today is " << static_cast<int>(d3) << endl;
	S s1 {S::str1};
	cout << "str1->" << static_cast<int>(s1) << endl; //�ַ���������� 
	cout << "str1->" << static_cast<char>(s1) << endl;
}
