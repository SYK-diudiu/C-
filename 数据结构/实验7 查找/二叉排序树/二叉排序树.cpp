#include <iostream>
#include <iomanip>
using namespace std;

typedef struct Node
{
	int data;
	int count;
	struct Node *left;
	struct Node *right;
}Node;

class BinaryTree
{
	private:
		Node *root;
		inline Node* getNode(int num); //�������� 
		Node* add(Node *p , int num); //�������������ӽڵ㣬������Create�� 
		void show(Node *p); //�����������������Print�� 
		int Find(Node *p , int target); //����target�������Ƿ����,���ڷ���1�������ڷ���0 ��������Search���� 
	public:
		/************************************/
		BinaryTree(int num = 0); //���캯��,����ʱͬ��������ڵ����� 
		void Create(int count = 0); //��������������,����count��ʾ�����ڵ�֮�⣬��Ҫ�����Ľڵ���� 
		void Print(); //�������������
		void Search(int target); //����target�Ƿ���������������ʾ���������ڣ��򽫸����ݲ��������������
};

BinaryTree::BinaryTree(int num)
{
	root = new Node;
	root->data = num;
	root->count = 1;
	root->left = NULL;
	root->right = NULL;
}

inline Node* BinaryTree::getNode(int num)
{
	Node *t = new Node;
	t->left = NULL;
	t->right = NULL;
	t->data = num;
	t->count = 1;
	
	return t;
}

Node* BinaryTree::add(Node *p , int num)
{
	if(p == NULL)
	{
		return this->getNode(num);
	}
	if(num == p->data)
	{
		p->count++;
		return p;
	}
	if(num < p->data)
	{
		if(p->left == NULL)
		{
			p->left = this->getNode(num);
			return p->left;
		}
		else
		{
			add(p->left , num);
		}
	}
	else if(num > p->data)
	{
		if(p->right == NULL)
		{
			p->right = this->getNode(num);
			return p->right;
		}
		else
		{
			add(p->right , num);
		}
	}
}

void BinaryTree::Create(int count)
{
	int number = 0;
	for(int i = 0 ; i < count ; ++i)
	{
		cout << "������ýڵ�����ݣ�";
		cin >> number;
		this->add(root , number);
	}
}

void BinaryTree::show(Node *p)
{
	if(p->left != NULL)
	{
		show(p->left);
	}
	cout << setw(3) << p->data << "\t" << setw(3) << p->count << endl;
	if(p->right != NULL)
	{
		show(p->right);
	}
}

void BinaryTree::Print()
{
	cout <<"**********************************" << endl;
	cout << "����\t" << "���ִ���" << endl; 
	show(root);
	cout <<"**********************************" << endl;
}

int BinaryTree::Find(Node *p , int target)
{
	if(target == p->data)
	{
		return 1;
	}
	if(target < p->data)
	{
		if(p->left != NULL)
		{
			if(Find(p->left , target))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
			return 0;
	}
	else if(target > p->data)
	{
		if(p->right != NULL)
		{
			if(Find(p->right , target))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
			return 0;
	}
} 

void BinaryTree::Search(int target)
{
	if(Find(root , target))
	{
		cout << "--->���ҵ�" << target << endl; 
	}
	else
	{
		cout << "--->û���ҵ�" << target << ",�ѳɹ��������ö�����" << endl;
		add(root , target); 
	}
}

int main()
{
	BinaryTree tree(45);
	tree.Create(5);
	tree.Print();
	tree.Create(1);
	tree.Print();
	tree.Search(37);
	tree.Print();
	tree.Search(20);
	tree.Print();	
}
