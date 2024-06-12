#include <iostream>
#include <string>
using namespace std;

typedef struct A
{
	string name;
	int number;
}stu;

class Student
{
	private:
		stu *array;
		int mid;
		int left;
		int right;
		int count;
		void Myswap(stu &a , stu &b); //��������ѧ����Ϣ��λ�� 
		int Find(int num); //�������֣�������Search���� 
		int Find(string na); //����������������Search���� 
	public:
		Student(int count); //��ʼ��Student���飬count��ʾѧ������ 
		void Num_sort(); //�������С�������� 
		void String_sort(); //�����ִ�С�������� 
		void Input(); //����ȫ������ 
		void Print(); //���ȫ������ 
		void Search(int num); //��ʾ������Ϣ 
		void Search(string na); //��ʾ������Ϣ 
};

Student::Student(int cou)
{
	this->count = cou;
	this->array = new stu[cou];
	left = 0;
	right = this->count-1;
	mid = (left+right)/2;
}

void Student::Input()
{
	for(int i = 0 ; i < this->count ; ++i)
	{
		cout << "������������";
		cin >> this->array[i].name;
		cout << "��������룺";
		cin >> this->array[i].number;
	}
}

void Student::Print()
{
	cout << endl << "------------------>" << endl;
	cout << "����\t" << "����" << endl;
	for(int i = 0 ; i < this->count ; ++i)
	{
		cout << this->array[i].name << "\t" << this->array[i].number << endl;
	}
	cout << "------------------>" << endl << endl;
}

void Student::Myswap(stu &a , stu &b)
{
	stu t = a;
	a = b;
	b = t;
}

void Student::Num_sort()
{
	for(int i = 0 ; i < this->count ; ++i)
	{
		for(int j = 0 ; j < this->count-i-1 ; ++j)
		{
			if(array[j].number > array[j+1].number)
			{
				this->Myswap(this->array[j] , this->array[j+1]); //����ѧ������ 
			}
		}
	}
}

void Student::String_sort()
{
	for(int i = 0 ; i < this->count ; ++i)
	{
		for(int j = 0 ; j < this->count-i-1 ; ++j)
		{
			if(array[j].name > array[j+1].name)
			{
				this->Myswap(this->array[j] , this->array[j+1]); //����ѧ������ 
			}
		}
	}
}

int Student::Find(int num)
{
	if(this->left > this->right)
	{
		return 0;
	}
	if(num == this->array[mid].number)
	{
		return 1;
	}
	if(num < this->array[mid].number)
	{
		this->right = mid-1;
		this->mid = (left+right)/2;
		if(Find(num))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(num > this->array[mid].number)
	{
		this->left = mid+1;
		this->mid = (left+right)/2;
		if(Find(num))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int Student::Find(string na)
{
	if(this->left > this->right)
	{
		return 0;
	}
	if(na == this->array[mid].name)
	{
		return 1;
	}
	if(na < this->array[mid].name)
	{
		this->right = mid-1;
		this->mid = (left+right)/2;
		if(Find(na))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(na > this->array[mid].name)
	{
		this->left = mid+1;
		this->mid = (left+right)/2;
		if(Find(na))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

void Student::Search(int num)
{
	//��ʼ��������������� 
	left = 0;
	right = this->count-1;
	mid = (left+right)/2;
	//���� 
	this->Num_sort();
	if(this->Find(num))
	{
		cout << "---> ������" << this->array[mid].name << "\t" << "���룺" << this->array[mid].number << endl;
	}
	else
	{
		cout << "û���ҵ���ѧ��" << endl; 
	}
}

void Student::Search(string na)
{
	//��ʼ��������������� 
	left = 0;
	right = this->count-1;
	mid = (left+right)/2;
	//���� 
	this->String_sort();
	if(this->Find(na))
	{
		cout << "---> ������" << this->array[mid].name << "\t" << "���룺" << this->array[mid].number << endl;
	}
	else
	{
		cout << "û���ҵ���ѧ��" << endl; 
	}
}

int main()
{
	int number = 0;
	string name;
	Student s(6);
	s.Input();
	s.Print();
	cin >> number;
	s.Search(number);
	cin >> name;
	s.Search(name);
}
