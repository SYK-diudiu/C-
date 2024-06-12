#include <iostream>
#include <fstream> // for file I/O�����ͷ�ļ�������iostreamͷ�ļ������Դ˴����Բ���ʾ����iostreamͷ�ļ�
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
	outFile.open(filename1.c_str()); // associate with a file  ���ļ��Ͷ����������� 
	//��������������ļ�����ʹ��һ�����ʽʵ�֣�ofstream fout("jar.txt"); // create fout object, associate it with jar.txt
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
	//��������������ļ�����ʹ��һ�����ʽʵ�� ifstream inFile(filename);
	if (!inFile.is_open()) // failed to open file
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);//EXIT_FAILURE����һ��ȫ�ֵĳ���
		//exit()��������ͷ�ļ�cstdlib����ͷ�ļ��������������ϵͳͨ�ŵĲ���ֵEXIT_FAILURE
	}
	double value;
	double sum = 0.0;
	int count = 0; // number of items read
	while (inFile>>value) // �ж϶�ȡ�Ƿ�ɹ�����ȡʧ�����˳�ѭ��
	{
		++count; // one more item read
		sum += value; // calculate running total
	}
	//�������������ȡ���һ������
	++count; // one more item read
	sum += value; // calculate running total
	//����ȡʧ�ܵ�ԭ��
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

