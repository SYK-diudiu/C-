#include <iostream>
#include <queue>
using namespace std;

typedef struct E
{
	int number;
	int w;
	struct E *next;
} Bian;

typedef struct V//���� 
{
	int number;
	Bian *first;
} Ding;

class Linjie
{
	private:
		Ding *Table; //ָ���ڽӱ��ָ�� 
		int ding_num; //�������� 
		int bian_num; //������ 
		int *help; //���ڱ����ĸ�������ָ��
		void Find_DFS(int number);
	public:
		Linjie(int ding = 0 , int bian = 0); //��ʼ���ڽӱ���������ֱ�Ϊ�������ͱ��� 
		void Create(); //�����ڽӱ� 
		void Print(); //��ӡ�ڽӱ� 
		void DFS(); //������ȱ��� 
		void BFS(); //������ȱ��� 
};

Linjie::Linjie(int ding , int bian)
{
	this->ding_num = ding;
	this->bian_num = bian;
	this->Table = new Ding[ding];
	this->help = new int[ding];	
	for(int i = 0 ; i < ding ; ++i)
	{
		help[i] = 0;
	}
} 

void Linjie::Create()
{
	for(int i = 0 ; i < this->ding_num ; ++i) //��ʼ���������������ͷ 
	{
		this->Table[i].number = i+1;
		this->Table[i].first = NULL;
	}
	int a = 0,b = 0;
	for(int i = 0 ; i < this->bian_num ; ++i)
	{
		cout << "������һ�������˶������ţ��ո����" << endl;
		cin >> a >> b;
		/*1*/ 
		Bian *t1 = new Bian; //������ʱ�ı� 
		t1->number = b; //�ߵ�����һ���������� 
		t1->w = 1; //�ߵ�Ȩֵ 
		t1->next = this->Table[a-1].first; //ͷ�� 
		this->Table[a-1].first = t1; //ͷ�� 
		/*2*///�ظ�1���ǻ����� 
		Bian *t2 = new Bian;
		t2->number = a;
		t2->w = 1;
		t2->next = this->Table[b-1].first;
		this->Table[b-1].first = t2;
	}
}

void Linjie::Print()
{
	for(int i = 0 ; i < this->ding_num ; ++i)
	{
		cout << (i+1);
		for(Bian *t = this->Table[i].first ; t != NULL ; t = t->next)
		{
			cout << "->" << t->number;	
		}	
		cout << endl;
	}	
} 

void Linjie::Find_DFS(int number)
{
	this->help[number] = 1;
	cout << this->Table[number].number << " ";
	Bian *t = this->Table[number].first;
	if(this->help[t->number-1] == 0)
	{
		this->Find_DFS(t->number-1);
	}
}

void Linjie::DFS() //������ȱ��� 
{
	for(int i = 0 ; i < this->ding_num ; ++i)
	{
		help[i] = 0;
	}
	for(int i = 0 ; i < this->ding_num ; ++i)
	{
		if(this->help[i] == 0)
		{
			this->Find_DFS(i);
		}
	}
}

void Linjie::BFS() //������ȱ��� 
{
	queue<int> Que;
	for(int i = 0 ; i < this->ding_num ; ++i)
	{
		help[i] = 0;
	}
	for(int i = 0 ; i < this->ding_num ; ++i)
	{
		if(this->help[i] == 0)
		{
			this->help[i] = 1;
			cout << this->Table[i].number << " ";
			Que.push(i);
			
			while(Que.empty() == true)
			{
				int index = 0;
				index = Que.front();
				Bian *t = this->Table[index].first; 
				while(t)
				{
					if(this->help[t->number-1] == 0)
					{
						this->help[t->number-1] = 1;
						cout << t->number << " ";
						Que.push(t->number-1);
						t = t->next;
					}
				}
			}
		}
	}
} 

int main()
{
	Linjie a(6 , 6);
	a.Create();
	a.Print();
	cout << "������ȱ�����" << endl; 
	a.DFS();
	cout << endl;
	cout << "������ȱ�����" << endl;
	a.BFS();
	
}
