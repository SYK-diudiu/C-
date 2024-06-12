#include <iostream>
#include <iomanip> //用于格式化流的输出 
using namespace std;

int main()
{
	int i = 123;
	float f = 4.56;
	cout << hex << i << " " << oct << i << endl;
	cout << setw(10) << i << " " << setfill('@') << setw(10) << i << endl;
}
