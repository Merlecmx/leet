#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define size 100
typedef struct{
        int vexs[size];
        int arcs[size][size];
        int vexnum;
        }MGraph;
 
void createMGraph(MGraph *mg)
{
     int i,j,n;
     scanf("%d",&(mg->vexnum));
     for (i = 0;i < mg->vexnum;i++)
         mg->vexs[i] = i+1;
     for (i = 0;i < mg->vexnum;i++)
     {
         for (j = 0;j < mg->vexnum;j++)
         {
             scanf("%d",&n);
             if (n == 0)
                 mg->arcs[i][j] = INT_MAX;
             else
                 mg->arcs[i][j] = n;
         }
     }
}

typedef struct
{
    int adjvex;
    int lowcost;
}AR;
  
int PRIM(MGraph mg,int n)
{
    int i,j,k,sum=0;
    AR closedge[size];
    int Q;
    scanf("%d",&Q);
    while (Q--)                   
    {
        scanf("%d %d",&i,&j);
        mg.arcs[i-1][j-1] = mg.arcs[j-1][i-1] = 0;
    }
    
    int visited[size] = {1};
    for(i = 0;i < mg.vexnum;i++)
    {
        if(i != n)
        {
            closedge[i].lowcost = mg.arcs[n][i];
            closedge[i].adjvex = n;
        }
    }
    visited[n] = 0;
    for(i = 1;i < mg.vexnum;i++)
    {
        int min = INT_MAX,index = n;
        for (k = 0;k < mg.vexnum;k++)
        {
            if(closedge[k].lowcost < min && closedge[k].lowcost!= 0 && closedge[k].lowcost!=INT_MAX)
            {
                min = closedge[k].lowcost;
                index = k;
            }
        }
        sum += closedge[index].lowcost;
        visited[index] = 0;
        
        for (j = 0;j < mg.vexnum;j++)
        {
            if (visited[j] && mg.arcs[index][j] < closedge[j].lowcost)
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
    MGraph G;
    createMGraph(&G);
    printf("%d",PRIM(G,G.vexs[0]));
    system("pause");
    return 0;
}
