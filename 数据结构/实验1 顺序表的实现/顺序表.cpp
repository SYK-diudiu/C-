#include <iostream>
#include <string>
#define OK 1
#define ERROR 0
#define Maxsize 10
using namespace std;

typedef struct
{
	int stu_class;
	string name;
} student;
typedef struct
{
	student *pstu;
	int length;
}Student_list;

inline int Create_student(Student_list &p) // n��ʾ������˳�����󳤶� 
{
	p.pstu= new student[Maxsize];
	p.length = 0;
	if(!p.pstu)
	{
		cout << "ѧ���б���ʧ�ܣ��ռ䲻��" << endl;
		return ERROR;
	}
	cout << "ѧ���б������" << endl;
	return OK;
}

int Input_student(Student_list &p)  //�������� 
{
	if(!p.pstu)
	{
		cout << "ѧ���б�δ�����������²���" << endl;
		return ERROR; 
	}
	int n = 0;
	int i = p.length;
	int memory = p.length;
	cout << "��������Ҫ�洢ѧ����Ϣ�ĸ�����";
	while(1)
	{
		cin >> n; 
		if(p.length+n > Maxsize)
		{
			cout << "�������洢�ռ�" << endl;
			cout << "����������: ";
			continue;
		}
		for(; i < (memory + n) ; ++i)
		{
			cout << "������ѧ�����ڰ༶��";
			cin >> p.pstu[i].stu_class;
			cout << "������ѧ��������"; 
			cin >> p.pstu[i].name;
			cout << endl;
			p.length++;
		}
		if(i == (memory + n))
		{
			cout << "��Ϣ¼����ϣ�����" << endl;
			break;
		}
	}
	return OK;
}
int Output_student(Student_list &p) //������� 
{
	if(!p.pstu)
	{
		cout << "ѧ���б�Ϊ�ջ򲻴��ڣ����ȴ����б�" << endl;
		return ERROR;
	}
	cout << "����Ϊѧ���б�" << endl << endl; 
	for(int i = 0 ; i < p.length ; ++i)
	{
		cout << i+1 << "��ѧ����" << endl;
		cout << "ѧ�����ڰ༶��";
		cout << p.pstu[i].stu_class << endl; 
		cout << "ѧ��������";
		cout << p.pstu[i].name << endl;
		cout << endl;
	}
	cout << endl << "������" << endl;
	return OK; 
}

int Insert_student(Student_list &p , int location)  //��������//location��ʾҪ�����λ�� 
{
	if(p.length+1 > Maxsize || location > Maxsize || location < 1)
	{
		cout << "��ǰ�ռ䲻���Բ������ݻ����λ�ò��Ϸ�" << endl;
		return ERROR; 
	}
	else
	{
		for(int i = p.length-1 ; i >= location - 1 ; --i)
		{
			p.pstu[i+1].name = p.pstu[i].name;
			p.pstu[i+1].stu_class = p.pstu[i].stu_class;
		}
		cout << "������ѧ�����ڰ༶��";
		cin >> p.pstu[location-1].stu_class;
		cout << "������ѧ��������"; 
		cin >> p.pstu[location-1].name;
		cout << endl;
		p.length++;
		return OK;
	}
}

int Delete_student(Student_list &p , int location)
{
	if(location < 1 || location > p.length)
	{
		cout << "ɾ��λ�ò��Ϸ�" << endl;
		return ERROR;
	}
	for(int i = location ; i <= p.length-1 ; ++i)
	{
		p.pstu[i-1].name = p.pstu[i].name;
		p.pstu[i-1].stu_class = p.pstu[i].stu_class;
	}
	p.length--;
	return OK;
}

inline int Check_student(Student_list &p , int location)
{
	if(!p.pstu)
	{
		cout << endl << "ѧ���б�Ϊ�ջ򲻴��ڣ������²���" << endl;
	}
	cout << location << "��ѧ����" << endl;
	cout << "ѧ�����ڰ༶��";
	cout << p.pstu[location-1].stu_class << endl; 
	cout << "ѧ��������";
	cout << p.pstu[location-1].name << endl;
	cout << endl;
}

int main()
{
	int num = 0;
	int loc = 0;
	Student_list stu;
	while(1)
	{
		int loc = 0;
		cout << "����������ִ�ж�Ӧ����" << endl;
		cout << "1������ѧ���б�" << endl;
		cout << "2����������" << endl;
		cout << "3���������" << endl;
		cout << "4���鿴����" << endl;
		cout << "5����������" << endl;
		cout << "6��ɾ������" << endl;
		cout << "7���˳�" << endl;
		cout << "������: ";
		cin >> num;
		switch(num)
		{
			case 1:
				Create_student(stu);
				break;
			case 2:
				Input_student(stu);
				break;
			case 3:
				Output_student(stu);
				break;
			case 4:
				cout << "������Ҫ�鿴��λ��" << endl;
				cin >> loc;
				Check_student(stu , loc);
				break;
			case 5:
				if(!stu.pstu)
				{
					cout << endl << "ѧ���б�Ϊ�ջ򲻴��ڣ������²���" << endl;
				}
				cout << "������Ҫ�����λ��" << endl;
				cin >> loc; 
				Insert_student(stu , loc);
				break;
			case 6:
				if(!stu.pstu)
				{
					cout << endl << "ѧ���б�Ϊ�ջ򲻴��ڣ������²���" << endl;
				}
				cout << "������Ҫɾ����λ��" << endl;
				cin >> loc;
				Delete_student(stu , loc);
				break; 
			case 7:
				exit(1); 
		}
	}
}
 
