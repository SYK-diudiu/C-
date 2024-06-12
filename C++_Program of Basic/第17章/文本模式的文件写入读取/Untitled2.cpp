#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	string filename = "syk.txt";
//	cout << "filename:";
//	cin >> filename;
	ofstream outFile;
	outFile.open(filename.c_str());
	outFile << "hello world!!!" << endl;
	outFile << "laobusidedongxi";
	outFile << "laobusidedongxi";
	outFile << "laobusidedongxi";
	outFile.close();
	string message[3];
	ifstream inFile;
	inFile.open(filename.c_str());
//	getline(inFile , message);
//	cout << message << endl;
//	cout << inFile.tellg() << endl; 
//	for(int i = 0 ; i < 2 ; ++i)
//	{
//		getline(inFile , message[i]);
//		cout << message[i] << endl;
//		cout << message[i].length() << endl;
//		cout << inFile.tellg() << endl; 
//	}

}
