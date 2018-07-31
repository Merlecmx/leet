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
     int i,j;
     scanf("%d",&(mg->vexnum));
     getchar();
     for (i = 0;i < mg->vexnum;i++)
         mg->vexs[i] = i;
     for (i = 0;i < mg->vexnum;i++)
     {
         for (j = 0;j < mg->vexnum;j++)
         {
             scanf("%d",&(mg->arcs[i][j]));
             getchar();
             //mg->arcs[j][i] = mg->arcs[i][j];
         }
     }
}

typedef struct
{
    int adjvex;
    int lowcost;
}closedge[size];
  
int PRIM(MGraph mg,int n)
{
    int i,j,k,sum=0;
    closedge closedge;
    //k = n;
    int Q,W;
    scanf("%d",&Q);
    W = Q;
    while (Q--)                   
    {
        scanf("%d %d",&i,&j);
        getchar();
        closedge[i].lowcost = 0;
        closedge[j].lowcost = 0;
    }
    
    for(i = 0;i < mg.vexnum;i++)
    {
        if(i != n)
        {
            closedge[i].lowcost = mg.arcs[n][i];
            closedge[i].adjvex = n;
        }
    }
    closedge[n].lowcost = 0;
    for(i = 1;i < mg.vexnum-W;i++)
    {
        int min = INT_MAX,index = n;
        for (k = 0;k < mg.vexnum;k++)
        {
            if(closedge[k].lowcost < min && closedge[k].lowcost!= 0)
            {
                min = closedge[k].lowcost;
                index = k;
            }
        }
        sum += closedge[index].lowcost;
        closedge[index].lowcost = 0;
        for (j = 0;j < mg.vexnum;j++)
        {
            if (mg.arcs[index][j] != 0 && mg.arcs[index][j] < closedge[j].lowcost)
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
