#include<iostream>
using namespace std;
 
#define INF 65535 //��ʾ��������������ֵҲ��
#define MaxVerNum  1000 //���嶥���������
 
typedef int cellType; //�����ڽӾ���Ԫ���������ͣ���Ȩֵ����������
 
//����ͼ�����ͷֱ�Ϊ����ͼ�������Ȩͼ������ͼ�������Ȩͼ 
typedef enum{
	UDG,UDN,DG,DN
}GraphKind; 
 
 
class GraphAdjMatrix
{
private: 
	int VerNum;//�������� 
	int ArcNum;//������ 
	GraphKind gKind; //ͼ���� 
	cellType** AdjMatrix;//�ڽӾ��� 
public:
	GraphAdjMatrix(); 
	void createGraph();//����ͼ	
	void GraphSet(int VerNum,int ArcNum,int kind);//ͼ�������� 
	int getVerNum() {return VerNum;}
	int getArcNum()	{return ArcNum;}
	GraphKind geyGraphKind() {return gKind;};
	void setMatrix(int i,int j,int w) ; //�ڽӾ������� 
	void printMatrix();//��ӡ�ڽӾ��� 
};
 
GraphAdjMatrix::GraphAdjMatrix()//���캯�� 
{
	AdjMatrix  = new cellType*[MaxVerNum];
	for(int i=0;i<MaxVerNum;i++)// Ϊ�ڽӾ�������ڴ� 
		AdjMatrix[i] = new cellType[MaxVerNum];
}
 
//void GraphAdjMatrix::setMatrix(int i,int j,int w) 
//{	
//	AdjMatrix[i][j]=w; 
//	if(gKind==UDG||gKind==UDN) //���������ͼ�������öԳ�λ��Ȩ�� 
//		AdjMatrix[j][i]=w;
//};
 
void GraphAdjMatrix::createGraph()
{
	int vn,an,k;//�ֱ���������������������Լ�ͼ���� 
	cout<<"���붥������,��������ͼ�����ÿո����"<<endl;
	cout<<"0-������Ȩͼ 1-�����Ȩͼ 2-������Ȩͼ 3-�����Ȩͼ"<<endl; 
	cin>>vn>>an>>k;
	VerNum = vn;
	ArcNum = an;
	gKind = (GraphKind)k;
	int i,j,w;
	
	//��ʼ���ڽӾ��� 
	for(int i=1;i<=vn;i++)
	{
		for(int j=1;j<=vn;j++)
		{
			AdjMatrix[i][j]=INF;
		}
	}
	/*����ͼ�������Ȩͼ������ͼ�������Ȩͼ */
	GraphKind gk;
	
	while(an--)
	{
		if (k == UDG || k == DG)//�������Ȩͼ���򽫱�Ȩ����Ϊ1 
		{
			cin>>i>>j;
			AdjMatrix[i][j]=1;
			if (k==UDG)//���������ͼ���Գ�λ������Ȩ�� 
				AdjMatrix[j][i]=1;
		}
		else
		{
			cin>>i>>j>>w;
			AdjMatrix[i][j]=w;
			if (k == UDN)//���������ͼ���Գ�λ������Ȩ�� 
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
