#include <fstream>
#include <iostream>
int main()
{
	std::ofstream out {"File.bin" , std::ios::app|std::ios::binary}; 
	for(int i = 0 ; i < 10 ; i++)
	{
		out << i << " ";
	}
	out.close();
}
