#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	std::ofstream out {"File.txt"}; 
	for(int i = 0 ; i < 10 ; i++)
	{
		out << i;
		if(i==0)
		{
			std::ofstream::pos_type here{out.tellp()};
			cout << here << " "  << sizeof(here)<< endl;
			here += 5;
			cout << here << " "  << sizeof(here)<< endl;
			out.seekp(here);
		}
	}
	auto length = out.seekp(0 , out.end).tellp();
	cout << "length: " << length << endl;
	out.close();
}
