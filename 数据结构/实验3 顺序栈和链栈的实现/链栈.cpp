#include <iostream>
using namespace std;
typedef struct
{
    int num;
} SElemType;
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;
void menu()
{

    cout << "=================================" << endl;
    cout << "1.ѹ��ջ��" << endl;
    cout << "2.�鿴ջ��Ԫ��" << endl;
    cout << "3.ȡջ��Ԫ��" << endl;
    cout << "4.������ջջ" << endl;
    cout << "5.�ÿ���ջ" << endl;
    cout << "6.����ת������" << endl;
    cout << "7.�˳�" << endl;
    cout << "=================================" << endl;
}
void Input(LinkStack &L) // ������ջ
{

    StackNode *q, *p = L;
    q = new StackNode;
    cin >> q->data.num;
    L = q;
    q->next = p;
}
void Check_front(LinkStack L) // ���ջ��
{
    cout << "ջ��Ԫ���ǣ�" << L->data.num << endl;
}
void Get_front(LinkStack &L, SElemType &nm) // ȡջ��Ԫ��
{
    nm.num = L->data.num;
    L = L->next;
}
void Show_stack(LinkStack L) // ������ջ
{
    while (L->next != NULL)
    {
        cout << L->data.num << " ";
        L = L->next;
    }
    cout << endl;
}
void Empty_stack(LinkStack &L) // �ÿ���ջ
{
    StackNode *p;
    while (L->next != NULL)
    {
        p = L;
        L = L->next;
        delete p;
    }
}
void Ten_to_eight(LinkStack &L, int k)//����ת��
{
   
    while(k >= 8)
    { 
        StackNode *q, *p = L;
        q = new StackNode;
        q->data.num = k % 8;
        L = q;
        q->next = p;
        k /= 8;
    }
    StackNode *q, *p = L;
    q = new StackNode;
    q->data.num = k;
    L = q;
    q->next = p;
    while (L->next != NULL)
    {
        cout << L->data.num;
        L = L->next;
    }
    cout << endl;
}
int main()
{
    StackNode *L;
    L = new StackNode;
    L->data.num = 0;
    L->next = NULL;
    while (1)
    {
    	menu();
        char option;
        cout << "��ѡ��";
        cin >> option;
        fflush(stdin);
        if(option < '1' || option > '8') 
        {
        	cout << "���벻�Ϸ�" << endl;
        	continue;
		}
        switch (option)
        {
        case '1':
            int m;
            cout << "��������Ҫ����Ԫ�ظ�����";
            cin >> m;
            cout << "��������Ҫ�����Ԫ��" << endl;
            for (int i = 0; i < m; i++)
            {
                Input(L);
            }
            cout << "����ɹ�" << endl;
            break;
        case '2':
            Check_front(L);
            break;
        case '3':
            SElemType s;
            Get_front(L, s);
            cout << "ջ��Ԫ���ǣ�" << s.num << endl;
            break;
        case '4':
            cout << "��ջ����ջ������Ϊ��";
            Show_stack(L);
            break;
        case '5':
            Empty_stack(L);
            cout << "�ÿճɹ�" << endl;
            break;
        case '6':
            int k;
            cout << "������Ҫת��������ʮ����ת�˽��ƣ���";
            cin >> k;
            cout << "ת����Ϊ��";
            Empty_stack(L);
            Ten_to_eight(L, k);
            break;
        case '7':
            cout<<"�˳��ɹ�"<<endl;
			exit(1);
        }
    }
}

