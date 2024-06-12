#include<iostream>
using namespace std;
 
#define INF 65535 //表示无穷大，其他合理的值也可
#define MaxVerNum  1000 //定义顶点最大数量
 
typedef int cellType; //定义邻接矩阵元素数据类型，即权值的数据类型
 
//定义图的类型分别为无向图，无向带权图，有向图，有向带权图 
typedef enum{
	UDG,UDN,DG,DN
}GraphKind; 
 
 
class GraphAdjMatrix
{
private: 
	int VerNum;//顶点数量 
	int ArcNum;//边数量 
	GraphKind gKind; //图类型 
	cellType** AdjMatrix;//邻接矩阵 
public:
	GraphAdjMatrix(); 
	void createGraph();//构建图	
	void GraphSet(int VerNum,int ArcNum,int kind);//图属性设置 
	int getVerNum() {return VerNum;}
	int getArcNum()	{return ArcNum;}
	GraphKind geyGraphKind() {return gKind;};
	void setMatrix(int i,int j,int w) ; //邻接矩阵设置 
	void printMatrix();//打印邻接矩阵 
};
 
GraphAdjMatrix::GraphAdjMatrix()//构造函数 
{
	AdjMatrix  = new cellType*[MaxVerNum];
	for(int i=0;i<MaxVerNum;i++)// 为邻接矩阵分配内存 
		AdjMatrix[i] = new cellType[MaxVerNum];
}
 
//void GraphAdjMatrix::setMatrix(int i,int j,int w) 
//{	
//	AdjMatrix[i][j]=w; 
//	if(gKind==UDG||gKind==UDN) //如果是无向图，则设置对称位置权重 
//		AdjMatrix[j][i]=w;
//};
 
void GraphAdjMatrix::createGraph()
{
	int vn,an,k;//分别代表顶点数量，边数量，以及图类型 
	cout<<"输入顶点数量,边数量，图类型用空格隔开"<<endl;
	cout<<"0-无向无权图 1-无向带权图 2-有向无权图 3-有向带权图"<<endl; 
	cin>>vn>>an>>k;
	VerNum = vn;
	ArcNum = an;
	gKind = (GraphKind)k;
	int i,j,w;
	
	//初始化邻接矩阵 
	for(int i=1;i<=vn;i++)
	{
		for(int j=1;j<=vn;j++)
		{
			AdjMatrix[i][j]=INF;
		}
	}
	/*无向图，无向带权图，有向图，有向带权图 */
	GraphKind gk;
	
	while(an--)
	{
		if (k == UDG || k == DG)//如果是无权图，则将边权重设为1 
		{
			cin>>i>>j;
			AdjMatrix[i][j]=1;
			if (k==UDG)//如果是无向图，对称位置设置权重 
				AdjMatrix[j][i]=1;
		}
		else
		{
			cin>>i>>j>>w;
			AdjMatrix[i][j]=w;
			if (k == UDN)//如果是无向图，对称位置设置权重 
				AdjMatrix[j][i]=w;
		}
	}
}
 
void GraphAdjMatrix::printMatrix()
{
	for(int i=1;i<=VerNum;i++)
	{
		for(int j=1;j<=VerNum;j++)
		{
			if (AdjMatrix[i][j]==INF)
				cout<<"*"<<"\t";
			else
				cout<<AdjMatrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}
 
int main()
{
	GraphAdjMatrix cg;
	cg.createGraph();
	cg.printMatrix();
	return 0;
}
