#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_SIZE 100
typedef struct{
    int vexs[MAX_SIZE];
    int arcs[MAX_SIZE][MAX_SIZE];
    int vexnum;
}MGraph;

void createMGraph(MGraph *mg,int n)
{
    int i,j,length;
    mg->vexnum = n;
    for (i = 0;i < mg->vexnum;i++)
        mg->vexs[i] = i+1;
    for (i = 0;i < mg->vexnum;i++)
    {
        for (j = 0;j < mg->vexnum;j++)
        {
            scanf("%d",&length);
            if (length == 0)
                mg->arcs[i][j] = INT_MAX;
            else
                mg->arcs[i][j] = length;
        }
    }
}

typedef struct
{
    int adjvex;
    int lowcost;
}AR;
// struct��ֵ��ֵ�������˷Ѻܶ�ʱ�䣬��ָ�봫���Ǹ��õ�ѡ��
int PRIM(MGraph mg)
{
    int i,j,k,sum=0;
    int id = 1;         // �� �� 1 ��ʼ�� 
    AR closedge[MAX_SIZE];
    int num_arg; //Q ���� queue�� ��T����num_args��
    scanf("%d",&num_arg);
    while (num_arg--)                   
    {
        scanf("%d%d",&i,&j);
        mg.arcs[i-1][j-1] = mg.arcs[j-1][i-1] = 0;
    }

    int visited[MAX_SIZE] = {0};
    for(i = 0;i < mg.vexnum;i++)      //��ʼ���������� 
    {
        if(i != id-1)
        {
            closedge[i].lowcost = mg.arcs[id-1][i];
            closedge[i].adjvex = id;
        }
    }
    visited[id-1] = 1;
    for(i = 1;i < mg.vexnum;i++)    //ʣ��vexnum-1 ���� 
    {
        int min = INT_MAX,index = id-1;
        for (k = 0;k < mg.vexnum;k++)     // ��ȡ��һ����λ�� 
        {
            if(!visited[k] && closedge[k].lowcost < min)
            {
                min = closedge[k].lowcost;
                index = k;
            }
        }
        sum += closedge[index].lowcost;
        visited[index] = 1;

        for (j = 0;j < mg.vexnum;j++)     //���¸������� 
        {
            if (!visited[j] && mg.arcs[index][j] < closedge[j].lowcost)
            {
                closedge[j].adjvex = mg.vexs[index];
                closedge[j].lowcost = mg.arcs[index][j];
            }
        }
    }
    return sum;
}

int main()
{
    int n; // the number of node
    while (scanf("%d", &n) != EOF){
        MGraph G;
        createMGraph(&G, n);
        printf("%d\n",PRIM(G));
    }
    return 0;
}
