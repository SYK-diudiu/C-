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
		void Myswap(stu &a , stu &b); //交换两个学生信息的位置 
		int Find(int num); //查找数字，内置于Search函数 
		int Find(string na); //查找姓名，内置于Search函数 
	public:
		Student(int count); //初始化Student数组，count表示学生人数 
		void Num_sort(); //按号码从小到大排序 
		void String_sort(); //按名字从小到大排序 
		void Input(); //输入全部数据 
		void Print(); //输出全部数据 
		void Search(int num); //显示查找信息 
		void Search(string na); //显示查找信息 
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
		cout << "请输入姓名：";
		cin >> this->array[i].name;
		cout << "请输入号码：";
		cin >> this->array[i].number;
	}
}

void Student::Print()
{
	cout << endl << "------------------>" << endl;
	cout << "姓名\t" << "号码" << endl;
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
				this->Myswap(this->array[j] , this->array[j+1]); //交换学生数据 
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
				this->Myswap(this->array[j] , this->array[j+1]); //交换学生数据 
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
	//初始化查找所需的数据 
	left = 0;
	right = this->count-1;
	mid = (left+right)/2;
	//排序 
	this->Num_sort();
	if(this->Find(num))
	{
		cout << "---> 姓名：" << this->array[mid].name << "\t" << "号码：" << this->array[mid].number << endl;
	}
	else
	{
		cout << "没有找到该学生" << endl; 
	}
}

void Student::Search(string na)
{
	//初始化查找所需的数据 
	left = 0;
	right = this->count-1;
	mid = (left+right)/2;
	//排序 
	this->String_sort();
	if(this->Find(na))
	{
		cout << "---> 姓名：" << this->array[mid].name << "\t" << "号码：" << this->array[mid].number << endl;
	}
	else
	{
		cout << "没有找到该学生" << endl; 
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
