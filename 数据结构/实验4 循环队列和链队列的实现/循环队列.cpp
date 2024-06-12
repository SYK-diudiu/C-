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
		cout << "**当前没有进行初始化操作，请先初始化**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if((Q.rear+1)%Maxsize == Q.front)
	{
		cout << "**********************" << endl;
		cout << "**队列已满，无法入队**" << endl;
		cout << "**********************" << endl;
		return ERROR;
	}
	cout << "请输入需要入队的元素：";
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
		cout << "**当前没有进行初始化操作，请先初始化**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if(Q.rear == Q.front)
	{
		cout << "**********************************" << endl;
		cout << "**当前队列为空，无法进行出队操作**" << endl;
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
		cout << "**当前没有进行初始化操作，请先初始化**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if(Q.rear == Q.front)
	{
		cout << "**********************************" << endl;
		cout << "**当前队列为空，无法读取队头元素**" << endl;
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
		cout << "**当前没有进行初始化操作，请先初始化**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if(Q.rear == Q.front)
	{
		cout << "**********************************" << endl;
		cout << "**当前队列为空，无法计算队列长度**" << endl;
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
		cout << "**当前没有进行初始化操作，请先初始化**" << endl;
		cout << "**************************************" << endl;
		return ERROR; 
	}
	else if(Q.rear == Q.front)
	{
		cout << "**********************************" << endl;
		cout << "**当前队列为空，无法进行输出操作**" << endl;
		cout << "**********************************" << endl;
		return ERROR; 
	}
	int num = 0; 
	int len = 0;
	Length_queue(Q , len);
	cout << "输出队列："; 
	for(int i = 0 ; i < len ; ++i)
	{
		num = Q.base[Q.front].data;
		Q.front = (Q.front+1)%Maxsize;
		cout << num << " ";
	}
	cout << endl;
	
	return OK;
}

void menu() //菜单 
{
	cout << "0、退出" << endl;  //finish
	cout << "1、初始化" << endl; //finish
	cout << "2、入队" << endl; //finish
	cout << "3、出队" << endl; //finish
	cout << "4、读队头元素" << endl; //finish
	cout << "5、统计队列长度" << endl; //finish
	cout << "6、输出队列" << endl; //finish
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
		cout << "请选择：";
		cin >> option;
		fflush(stdin);
		if(option < '0' || option > '6')
		{
			cout << "**************" << endl;	
			cout << "**输入不合法**" << endl;	
			cout << "**************" << endl;	
			continue; 
		} 
		switch(option)
		{
			case '0':
				cout << "*****************" << endl;
				cout << "**退出成功！!！**" << endl;
				cout << "*****************" << endl;
				exit(1);
			case '1':
				if(Initial_queue(Q))
				{
					cout << "**************" << endl;
					cout << "**初始化成功**" << endl;
					cout << "**************" << endl;
				}
				else
				{
					cout << "**************" << endl;	
					cout << "**初始化失败**" << endl;	
					cout << "**************" << endl;	
				} 
				break;
			case '2':
				Push_queue(Q); 
				break;
			case '3':
				Pop_queue(Q , get);
				cout << "出队元素为：" << get << endl;
				cout << endl;
				break;
			case '4':
				Gethead_queue(Q , get);
				cout << "队头元素为：" << get << endl;
				cout << endl;
				break;
			case '5':
				Length_queue(Q , length);
				cout << "队列长度为：" << length << endl;
				cout << endl;
				break;
			case '6':
				Output_queue(Q);
				break;
		}
	}
}







