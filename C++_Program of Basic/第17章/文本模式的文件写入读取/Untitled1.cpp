#include <iostream>
#include <fstream> // for file I/O，这个头文件包含了iostream头文件，所以此处可以不显示包含iostream头文件
#include <cstdlib> // support for exit()
const int SIZE = 60;
int main()
{
	using namespace std;
	cout << "ofstream*********************************************************************" << endl;
	char automobile[50];
	int year;
	double a_price;
	double d_price;
	string filename1;
	cout << "Enter name for new file: ";
	cin >> filename1;
	while (cin.get() != '\n');
	ofstream outFile; // create object for output
	outFile.open(filename1.c_str()); // associate with a file  将文件和对象链接起来 
	//创建对象和连接文件可以使用一个表达式实现：ofstream fout("jar.txt"); // create fout object, associate it with jar.txt
	cout << "Enter the make and model of automobile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	d_price = 0.913 * a_price;
	// display information on screen with cout
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;
	// now do exact same things using outFile instead of cout
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;
	outFile.close(); // done with file
	cout << "ifstream*********************************************************************" << endl;
	while (cin.get() != '\n');
	char filename[SIZE];
	ifstream inFile; // object for handling file input
	cout << "Enter name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename); // associate inFile with a file
	//创建对象和连接文件可以使用一个表达式实现 ifstream inFile(filename);
	if (!inFile.is_open()) // failed to open file
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);//EXIT_FAILURE就是一个全局的常量
		//exit()：定义在头文件cstdlib，该头文件还定义了与操作系统通信的参数值EXIT_FAILURE
	}
	double value;
	double sum = 0.0;
	int count = 0; // number of items read
	while (inFile>>value) // 判断读取是否成功，读取失败则退出循环
	{
		++count; // one more item read
		sum += value; // calculate running total
	}
	//因此在这加两句读取最后一个数据
	++count; // one more item read
	sum += value; // calculate running total
	//检查读取失败的原因
	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";
	if (count == 0)
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}
	inFile.close(); // finished with the file

	return 0;
}

