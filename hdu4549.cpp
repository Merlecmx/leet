#include<iostream>
using namespace std;
#define MOD 1000000007
#define N 2
typedef long long LL;
class item {
public:
	item() = default;
	LL ar[N][N];
	item operator *(const item &rhs) {
		item temp;
		int i,j,k;
		for (i = 0; i < N;i++)
		{
			for (j = 0;j < N;j++)
			{
				temp.ar[i][j] = 0;
				for (k = 0;k < N;k++)
				{
					temp.ar[i][j] += ar[i][k] * rhs.ar[k][j];
					temp.ar[i][j] %= (MOD - 1);
				}
			}
		}
		return temp;
	}
	void pow_matrix(int k);
};
item ans,res;      // 全局变量 
void item::pow_matrix(int k)
{
	int i,j;
	for (i = 0;i < N;i++)
	{
		for (j = 0;j < N;j++){
			ans.ar[i][j] = (i == j);
		}
	}
	while (k)
	{
		if (k & 1)
			ans = ans * res;
		res = res * res ;
		k >>= 1;
	}
}
LL pow_num(LL a,LL n)
{
	LL temp = 1;
	a %= MOD;
	while (n)
	{
		if (n & 1){
			temp *= a;
			temp %= MOD;
		}
		a *= a;
		a %= MOD;
		n >>= 1;
	}
	return temp;
}
int main()
{
	int a,b,n;
	while (scanf("%d %d %d",&a,&b,&n) != EOF)
	{
		res.ar[0][0] = 0;
		res.ar[0][1] = res.ar[1][0] = res.ar[1][1] = 1;
		res.pow_matrix(n);
		int target = (pow_num(a,ans.ar[0][0]) * pow_num(b,ans.ar[1][0]))% MOD;
		printf("%d\n",target);
	}
	return 0;
}
