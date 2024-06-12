#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define Maxsize 5

typedef struct Node
{
	int data;
}Node;
typedef struct Queue
{
	Node *base;
	int front;
	int rear;
}Queue;

int Initial_queue(Queue &Q)
{
	Q.base = new Node[Maxsize];
	if(!Q.base)
	{
		return ERROR;
	}
	Q.front = Q.rear = 0;
	
	return OK;
}

int Push_queue(Queue &Q)
{
	if(!Q.base)
	{
		cout << "**************************************" << endl;
		cout << "**��ǰû�н��г�ʼ�����������ȳ�ʼ��**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if((Q.rear+1)%Maxsize == Q.front)
	{
		cout << "**********************" << endl;
		cout << "**�����������޷����**" << endl;
		cout << "**********************" << endl;
		return ERROR;
	}
	cout << "��������Ҫ��ӵ�Ԫ�أ�";
	int num = 0;
	cin >> num;
	fflush(stdin);
	Q.base[Q.rear].data = num;
	Q.rear = (Q.rear+1)%Maxsize;
	
	return OK;
}

int Pop_queue(Queue &Q , int &e)
{
	if(!Q.base)
	{
		cout << "**************************************" << endl;
		cout << "**��ǰû�н��г�ʼ�����������ȳ�ʼ��**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if(Q.rear == Q.front)
	{
		cout << "**********************************" << endl;
		cout << "**��ǰ����Ϊ�գ��޷����г��Ӳ���**" << endl;
		cout << "**********************************" << endl;
		return ERROR; 
	}
	e = Q.base[Q.front].data;
	Q.front = (Q.front+1)%Maxsize;
	
	return OK;
}

int Gethead_queue(Queue &Q , int &e)
{
	if(!Q.base)
	{
		cout << "**************************************" << endl;
		cout << "**��ǰû�н��г�ʼ�����������ȳ�ʼ��**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if(Q.rear == Q.front)
	{
		cout << "**********************************" << endl;
		cout << "**��ǰ����Ϊ�գ��޷���ȡ��ͷԪ��**" << endl;
		cout << "**********************************" << endl;
		return ERROR; 
	}
	e = Q.base[Q.front].data;
	 
	return OK;
}

int Length_queue(Queue &Q , int &length)
{
	if(!Q.base)
	{
		cout << "**************************************" << endl;
		cout << "**��ǰû�н��г�ʼ�����������ȳ�ʼ��**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if(Q.rear == Q.front)
	{
		cout << "**********************************" << endl;
		cout << "**��ǰ����Ϊ�գ��޷�������г���**" << endl;
		cout << "**********************************" << endl;
		length = 0;
		return ERROR; 
	}
	length = (Q.rear - Q.front + Maxsize)%Maxsize;
	
	return OK;
}

int Output_queue(Queue &Q)
{
	if(!Q.base)
	{
		cout << "**************************************" << endl;
		cout << "**��ǰû�н��г�ʼ�����������ȳ�ʼ��**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if(Q.rear == Q.front)
	{
		cout << "**********************************" << endl;
		cout << "**��ǰ����Ϊ�գ��޷������������**" << endl;
		cout << "**********************************" << endl;
		return ERROR; 
	}
	int num = 0; 
	int len = 0;
	Length_queue(Q , len);
	cout << "������У�"; 
	for(int i = 0 ; i < len ; ++i)
	{
		num = Q.base[Q.front].data;
		Q.front = (Q.front+1)%Maxsize;
		cout << num << " ";
	}
	cout << endl;
	
	return OK;
}

void menu() //�˵� 
{
	cout << "0���˳�" << endl;  //finish
	cout << "1����ʼ��" << endl; //finish
	cout << "2�����" << endl; //finish
	cout << "3������" << endl; //finish
	cout << "4������ͷԪ��" << endl; //finish
	cout << "5��ͳ�ƶ��г���" << endl; //finish
	cout << "6���������" << endl; //finish
	cout << "===========================" << endl; 
}

int main()
{
	Queue Q;
	Q.base = NULL;
	int length = 0;

	int get = 0;
	char option;
	while(1)
	{
		menu();
		cout << "��ѡ��";
		cin >> option;
		fflush(stdin);
		if(option < '0' || option > '6')
		{
			cout << "**************" << endl;	
			cout << "**���벻�Ϸ�**" << endl;	
			cout << "**************" << endl;	
			continue; 
		} 
		switch(option)
		{
			case '0':
				cout << "*****************" << endl;
				cout << "**�˳��ɹ���!��**" << endl;
				cout << "*****************" << endl;
				exit(1);
			case '1':
				if(Initial_queue(Q))
				{
					cout << "**************" << endl;
					cout << "**��ʼ���ɹ�**" << endl;
					cout << "**************" << endl;
				}
				else
				{
					cout << "**************" << endl;	
					cout << "**��ʼ��ʧ��**" << endl;	
					cout << "**************" << endl;	
				} 
				break;
			case '2':
				Push_queue(Q); 
				break;
			case '3':
				Pop_queue(Q , get);
				cout << "����Ԫ��Ϊ��" << get << endl;
				cout << endl;
				break;
			case '4':
				Gethead_queue(Q , get);
				cout << "��ͷԪ��Ϊ��" << get << endl;
				cout << endl;
				break;
			case '5':
				Length_queue(Q , length);
				cout << "���г���Ϊ��" << length << endl;
				cout << endl;
				break;
			case '6':
				Output_queue(Q);
				break;
		}
	}
}







