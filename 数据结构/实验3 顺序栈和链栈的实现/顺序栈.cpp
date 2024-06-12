#include <iostream>
using namespace std;

#define ERROR 0
#define OK 1
#define MAXSIZE 10
typedef struct
{
	int *base;
	int front;
	int back;
	int stacksize;
} Stack; 

int Create_stack(Stack *S)
{
	S->base = new int[MAXSIZE];
	if(!S->base)
	{
		cout << "����˳��ջʧ��" << endl;
		return ERROR;
	}
	S->back = S->front = 0;
	S->stacksize = MAXSIZE;
	cout << "�����ɹ�" << endl;
	return OK;
}

int Push_front(Stack *S , int e) //��ջ��e��ʾ��Ҫ��ջ��Ԫ�� 
{
	if(S->front - S->back == S->stacksize)
	{
		cout << "ջ��" << endl;
		return ERROR; 
	}
	S->base[S->front++] = e;
	return OK; 
}

int Pop_front(Stack *S) //ɾ��ջ��Ԫ��
{
	if(S->front - S->back == 0)
	{
		cout << "��ջ��û�п�ɾ��Ԫ��" << endl;
		return ERROR;
	}
	S->base[--S->front] = 0;
	cout << "ɾ���ɹ�" << endl;
	return OK;
} 

int Get_front(Stack *S , int &e) //ȡջ��Ԫ��
{
	if(S->front - S->back == 0)
	{
		cout << "��ջ���޷�ȡ��ջ��Ԫ��" << endl;
		return ERROR;
	}
	--S->front;
	e = S->base[S->front]; //ȡ��Ԫ�� 
	S->base[S->front] = 0; //����ȡ��λ�õ�ֵΪ0 
}

int Show_stack(Stack *S) //����˳��ջ
{
	if(S->front - S->back == 0)
	{
		cout << "��ջ���޷�����ջ��Ԫ��" << endl;
		return ERROR;
	}
	int length = S->front - S->back;
	cout << "��ջ����ջ������Ϊ��" << endl; 
	for(int i = length-1 ; i >= 0 ; --i) //ʵ�ֱ������� 
	{
		cout << S->base[i] << "\t";
	}
	cout << endl;
	return OK;
}

int Empty_stack(Stack *S)
{
	if(S->front - S->back == 0)
	{
		cout << "��ջ�������ÿղ���" << endl;
		return ERROR;
	}
	int length = S->front - S->back;
	for(int i = length-1 ; i >= 0 ; --i)
	{
		S->base[i] = 0;	
	} 
	S->front = S->back; //��ʼ��ջ�ڱ�� 
	cout << "�ÿ���ϣ�" << endl; 
}

int Ten_to_eight(Stack *S , int &e)
{
	if(S->front - S->back > 0)
	{
		cout << "��ǰջ��Ϊ�գ��޷�����ת���������ÿ�ջ" << endl;
		return ERROR;
	}
	int temp = e;
	e = 0;
	int yu = 0;
	while(temp) //ת������ջ 
	{
		yu = temp%8;
		Push_front(S , yu);
		temp /= 8;
	}
	int length = S->front - S->back;
	int t = 0;
	while(length--) //��ջ��� 
	{
		e *= 10;
		Get_front(S , t);
		e += t;
	}
	cout << "����ת����Ϊ��" << e << endl;
}

void menu()
{
	cout << "1����ʼ��ջ" << endl; //finish
	cout << "2������Ԫ�أ���ջ��" << endl; //finish
	cout << "3��ɾ��ջ��Ԫ��" << endl; //finish
	cout << "4��ȡջ��Ԫ��" << endl; //finish
	cout << "5������˳��ջ" << endl; //finish 
	cout << "6���ÿ�˳��ջ" << endl; //finish 
	cout << "7������ת��" << endl;
	cout << "8���˳�����" << endl;
	cout << "-------------------------------->>" << endl;
}

int main()
{
	Stack *stack = new Stack;
	stack == NULL;
	char option;
	int num = 0;
	while(1) 
	{
		menu();
		cout << "��ѡ��Ҫִ�еĲ�����";
		cin >> option;
		fflush(stdin);
		if(option < '1' || option > '8')
		{
			cout << "���벻�Ϸ�" << endl;
			continue;	
		}
		switch(option)
		{
		case '1':
			Create_stack(stack); 
			break;
		case '2':
			cout << "��������Ҫ��ջ�����֣�";
			cin >> num; 
			Push_front(stack , num);
			break;
		case '3':
			Pop_front(stack);
			break;
		case '4':
			Get_front(stack , num);
			cout << "ȡ����ֵΪ��" << num << endl;
			break;
		case '5':
			Show_stack(stack);
			break;
		case '6':
			Empty_stack(stack);
			break;
		case '7':
			cout << "��������Ҫת�������֣�ʮ����ת�˽��ƣ���";
			cin >> num;
			Ten_to_eight(stack , num);
			break;
		case '8':
			cout << "�˳��ɹ�" << endl;
			exit(1);
			break;	
		}	
	}
}
