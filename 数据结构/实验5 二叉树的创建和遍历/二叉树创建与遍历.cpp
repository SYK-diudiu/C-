#include <iostream>
#include <string>
using namespace std;

char ch;
int m = 0;
int n = 0;
int leaves = 0;
typedef struct TreeNode
{
	char data;
	struct TreeNode *left;
	struct TreeNode *right;
}node, *Node;

void DLR(Node &T)
{
	if(T)
	{
		cout << T->data ;
		DLR(T->left);
		DLR(T->right);
	}
}

void LDR(Node &T)
{
	if(T)
	{
		LDR(T->left);
		cout << T->data ;
		LDR(T->right);
	}
}

void LRD(Node &T)
{
	if(T)
	{
		LRD(T->left);
		LRD(T->right);
		cout << T->data ;
	}
}

void Create(Node &T) //������������ 
{
	cin >> ch;
	if(ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = new node;
		T->data = ch;
		Create(T->left);
		Create(T->right);		
	}
}

int Depth(Node &T)
{
	if(T==NULL)
	{
		return 0;
	}
	else
	{
		m = Depth(T->left);
		n = Depth(T->right);
		if(m>n)
		{
			return (m+1);
		}
		else
		{
			return (n+1);
		}
	}
}
int NodeCount(Node &T)
{
	if(T == NULL)
	{
		return 0;
	}
	else
	{
		return NodeCount(T->left) + NodeCount(T->right) + 1;
	}
}

int Leaves(Node &T)
{
	if(T)
	{
		if(T->left == NULL && T->right == NULL)
		{
			return leaves+1;
		}
		leaves = Leaves(T->left);
		leaves = Leaves(T->right);
	}
	return leaves;
}

int Find(Node &T , char e)
{
	if(T)
	{
		if(Find(T->left , e))
		{
			return 1;
		}
		if(T->data == e)
		{
			return 1;
		}
		if(Find(T->right , e))
		{
			return 1;
		}
	}
	return 0;
}
void Check(Node &T , char e)
{
	if(Find(T , e))
	{
		cout << "���ҳɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}
}
int main()
{
	char find;
	Node top = NULL;
	cout << "����������" << endl;
	Create(top);
	cout << "����������" << endl;
	DLR(top);
	cout << endl;
	cout << "�б������" << endl;
	LDR(top);
	cout << endl;
	cout << "����������" << endl;
	LRD(top);
	cout << endl;
	cout << "���������" << NodeCount(top) << endl;
	cout << "Ҷ�ӽ��������" << Leaves(top) << endl;
	cout << "��ȣ�" << Depth(top) << endl;
	cout << "������Ҫ���ҵ����ݣ�";
	cin >> find;
	Check(top , find);
	cout << "������Ҫ���ҵ����ݣ�";
	cin >> find;
	Check(top , find);
}










