#include<iostream>
#include<queue>
using namespace std; 
#define MVNum 100 //最大顶点数

typedef struct ArcNode{
 	int adjvex;  //该边所指向的顶点的位置 
 	struct ArcNode *nextarc;//指向下一条边的指针 
}ArcNode;

//顶点的结点结构 
typedef struct VNode{
 	char data;//顶点信息、
 	ArcNode *firstarc;//指向第一条依附该顶点的边的指针 
}VNode,AdjList[MVNum];//AdjList表示邻接表类型


//图的结构定义 
typedef struct{
 	AdjList vertices; //定义一个数组vertices,是vertex的复数形式
 	int vexnum,arcnum; //图的当前顶点数和弧数
}ALGraph;

int LocateVex(ALGraph G,int u){
 //在图G中查找顶点u，存在则返回顶点表中的下标；否则返回-1
 	int i;
 	for(i=1;i<=G.vexnum;i++)
  	if(u == G.vertices[i].data)
   		return i;
  	return -1;
} 

//创建无向图G 
bool CreateUDG(ALGraph &G){ 
 	

 	cout << "请输入总结点数和总边数：" << endl; 
 	cin>>G.vexnum>>G.arcnum;//输入总顶点数，总边数
 	cout << " 输入各顶点值： " << endl; 
 	for(int i = 1;i <= G.vexnum;i++)
	{//输入各顶点，构造表头结点表 
  		cin>>G.vertices[i].data;//输入顶点值 
  		G.vertices[i].firstarc=NULL;//初始化表头结点的指针域
	}//for
	getchar();
 	//输入各边，构造邻接表
 
 	cout << "输入一条边依附的两个顶点值"<<endl; 
 	for(int k=1;k<=G.arcnum;k++){
 	char v1,v2;
 	cin>>v1>>v2;    //输入一条边依附的两个顶点 
 	getchar();
 	
 	int i=LocateVex(G,v1);
 	int j=LocateVex(G,v2); //确定顶点在G.vertices中的序号
 	ArcNode *p1=new ArcNode;  //生成一个新的边结点*p1
  	p1->adjvex=j;  //邻接点序号为j 
  //头插法将新结点*p1插入顶点vi的边表头部 
 	p1->nextarc=G.vertices[i].firstarc;
 	G.vertices[i].firstarc=p1; 
 	ArcNode *p2=new ArcNode;
 	p2->adjvex=i;  //邻接点序号为i
 	//头插法插入p2 ,因为是无向网，所以是两条 
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
	
	cout << "输出邻接表： " <<endl;
	
	for(int i = 1; i<= G.vexnum; i++)
	{
		cout << G.vertices[i].data;
		for(p = G.vertices[i].firstarc; p != NULL; p = p->nextarc)
			printf("->%d", p->adjvex);
		cout << endl; 
	} 
		return 0;
}


