#include <fstream>
#include <iostream>
int main()
{
	int get = 0;
	std::ifstream in {"File.bin" , std::ios::in|std::ios::binary};
	in.is_open(); 
	while(true)
	{
		in >> get;
		if(in.eof()) break;
		std::cout << get;
	}	
	in.close();
}
