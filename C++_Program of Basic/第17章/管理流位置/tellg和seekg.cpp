#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int get = 0;
	std::ifstream in {"File.txt"}; 	
	in.seekg(+5 , in.beg); 
	while(true)
	{
		in >> get;
		if(in.eof()) break;
		std::cout << get;
//		cout << in.tellg() << " " << endl;
	}	
	in.close();
}
