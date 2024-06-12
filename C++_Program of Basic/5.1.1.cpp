#include <iostream>
using namespace std;

int main()
{
	int array[3]{1 , 2 , 3}; //本代码为了记录数组的这种定义并初始化的方式 
/*或者：int array[3] = {1 , 2 , 3};*/
//中括号和花括号中间是可以没有等号的，即使加上等号，程序也不会出错 
	for(int i = 0 ; i < 3 ; ++i)
		cout << "array[" << i << "]-->" << array[i] << endl;
	cout << sizeof(array) << endl; //返回值是整个数组占用的总字节数，在这里输出的就是12 
} 
