#include <iostream>
using namespace std;

//枚举类型默认是int类型 
enum class Day
{
	Monday = 1 , Tuesday , Wednesday , Thursday , Friday = 9 , Saturday = Monday + 1 , Sunday 
};

//枚举类型可以设置初值为char类型，事实上可以是默认int类型之外的所有类型，不只是char，但是string不可以 
enum class S
{
	str1 = 'a' , str2 = 'b' 
};

int main()
{
	//练习使用enum的 同时 演示三种赋值方法 
	Day d1 = Day::Monday; 
	Day d2 {Day::Friday};
	Day d3 = {Day::Sunday};
	cout << "Today is " << static_cast<int>(d1) << endl;
	cout << "Today is " << static_cast<int>(d2) << endl;
	cout << "Today is " << static_cast<int>(d3) << endl;
	S s1 {S::str1};
	cout << "str1->" << static_cast<int>(s1) << endl; //字符以整型输出 
	cout << "str1->" << static_cast<char>(s1) << endl;
}
