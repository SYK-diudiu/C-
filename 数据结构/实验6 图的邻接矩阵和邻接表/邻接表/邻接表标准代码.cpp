#include<iostream>
#include<queue>
using namespace std; 
#define MVNum 100 //��󶥵���

typedef struct ArcNode{
 	int adjvex;  //�ñ���ָ��Ķ����λ�� 
 	struct ArcNode *nextarc;//ָ����һ���ߵ�ָ�� 
}ArcNode;

//����Ľ��ṹ 
typedef struct VNode{
 	char data;//������Ϣ��
 	ArcNode *firstarc;//ָ���һ�������ö���ıߵ�ָ�� 
}VNode,AdjList[MVNum];//AdjList��ʾ�ڽӱ�����


//ͼ�Ľṹ���� 
typedef struct{
 	AdjList vertices; //����һ������vertices,��vertex�ĸ�����ʽ
 	int vexnum,arcnum; //ͼ�ĵ�ǰ�������ͻ���
}ALGraph;

int LocateVex(ALGraph G,int u){
 //��ͼG�в��Ҷ���u�������򷵻ض�����е��±ꣻ���򷵻�-1
 	int i;
 	for(i=1;i<=G.vexnum;i++)
  	if(u == G.vertices[i].data)
   		return i;
  	return -1;
} 

//��������ͼG 
bool CreateUDG(ALGraph &G){ 
 	

 	cout << "�������ܽ�������ܱ�����" << endl; 
 	cin>>G.vexnum>>G.arcnum;//�����ܶ��������ܱ���
 	cout << " ���������ֵ�� " << endl; 
 	for(int i = 1;i <= G.vexnum;i++)
	{//��������㣬�����ͷ���� 
  		cin>>G.vertices[i].data;//���붥��ֵ 
  		G.vertices[i].firstarc=NULL;//��ʼ����ͷ����ָ����
	}//for
	getchar();
 	//������ߣ������ڽӱ�
 
 	cout << "����һ������������������ֵ"<<endl; 
 	for(int k=1;k<=G.arcnum;k++){
 	char v1,v2;
 	cin>>v1>>v2;    //����һ������������������ 
 	getchar();
 	
 	int i=LocateVex(G,v1);
 	int j=LocateVex(G,v2); //ȷ��������G.vertices�е����
 	ArcNode *p1=new ArcNode;  //����һ���µı߽��*p1
  	p1->adjvex=j;  //�ڽӵ����Ϊj 
  //ͷ�巨���½��*p1���붥��vi�ı߱�ͷ�� 
 	p1->nextarc=G.vertices[i].firstarc;
 	G.vertices[i].firstarc=p1; 
 	ArcNode *p2=new ArcNode;
 	p2->adjvex=i;  //�ڽӵ����Ϊi
 	//ͷ�巨����p2 ,��Ϊ�������������������� 
 	p2->nextarc=G.vertices[j].firstarc;
 	G.vertices[j].firstarc=p2; 
 }//for
  return true; 
}//CreateUDG



int main()
{
	ALGraph G;
	ArcNode *p;
	CreateUDG(G);
	
	cout << "����ڽӱ� " <<endl;
	
	for(int i = 1; i<= G.vexnum; i++)
	{
		cout << G.vertices[i].data;
		for(p = G.vertices[i].firstarc; p != NULL; p = p->nextarc)
			printf("->%d", p->adjvex);
		cout << endl; 
	} 
		return 0;
}


