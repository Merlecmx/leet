#include<stdio.h>
#include<stdlib.h>
typedef struct matrix {
	int ar[11][11];
}matrix;
matrix ans,res;
matrix Mul(matrix A,matrix B,int n)
{
	int i,j,k;
	matrix temp;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			temp.ar[i][j] = 0;
			for (k = 0;k < n;k++)
			{
				temp.ar[i][j] += A.ar[i][k] * B.ar[k][j];
			}
			temp.ar[i][j] %= 9973;
		}
	}
	return temp;
}
matrix Pow(int n,int k)
{
	int i,j;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++){
			ans.ar[i][j] = (i == j);
		}
	}
	while (k)
	{
		if (k & 1)
			ans = Mul(ans,res,n);
		res = Mul(res,res,n);
		k >>= 1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int i,j,n,k;
		scanf("%d %d",&n,&k);
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < n;j++){
				scanf("%d",&res.ar[i][j]);
			}
		}
		Pow(n,k);
		int sum = 0;
		for (i = 0;i < n;i++)
			sum += ans.ar[i][i];
		printf("%d\n",sum % 9973);
	}
	return 0;
}
