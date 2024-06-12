#include <iostream>
using namespace std;

int main()
{
	
	/**********基于区域的for循环**********/
	 
	int values[] {1,2,3,4,5,6,7,8,9};
	for(int x : values)
	{
		//程序会按照vlaues数组中的顺序逐个给x赋值并输出 
		cout << "x-->" << x << endl; 
	}
	
}
