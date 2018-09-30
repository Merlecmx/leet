#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 4
int dfs_game(double* ct,int size)
{
 		for (int i = 0;i < SIZE;i++)
 		{
		 		if (ct[i] != (int)ct[i])
		 		    return 0;
    }
    if (size == 1){
        if (ct[0] == 24)
            return 1;
        return 0;
    }
    for (int i = 0;i < size;i++)
    {
        for (int j = i+1;j < size;j++)
        {
            double a = ct[i];
            double b = ct[j];
            ct[j] = ct[size-1];
            
            ct[i] = a + b;
            if (dfs_game(ct,size-1)) return 1;
            
            ct[i] = a - b;
            if (dfs_game(ct,size-1)) return 1;
            
            ct[i] = b - a;
            if (dfs_game(ct,size-1)) return 1;
            
            ct[i] = a * b;
            if (dfs_game(ct,size-1)) return 1;
            
            if (b != 0){
                ct[i] = a / b;
                if (dfs_game(ct,size-1)) return 1;
            }
            if (a != 0){
                ct[i] = b / a;
                if (dfs_game(ct,size-1)) return 1;
            }
            
            ct[i] = a;
            ct[j] = b;
        }
    }
    return 0;
}
int main()
{
 		char temp[4][3];
 		double* ct = (double*)malloc(sizeof(double) * SIZE);
 		while ( scanf("%s %s %s %s",temp[0],temp[1],temp[2],temp[3]) != EOF)
 		{
		 			getchar();
        for (int i = 0;i < SIZE;i++)
        {
		        if (temp[i][0] == 'A')
						    ct[i] = 1;
		        else if (temp[i][0] == 'J')
		            ct[i] = 11;
						else if (temp[i][0] == 'Q')
						    ct[i] = 12;
		        else if (temp[i][0] == 'K')
		            ct[i] = 13;
            else if (temp[i][0] == '1')
                ct[i] = 10;
		        else
						    ct[i] = temp[i][0] - '0';
			  }
			  if (dfs_game(ct,SIZE))
			      printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
