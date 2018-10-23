#include<iostream>
using namespace std;
#define SIZE 11
#define MOD 9973
int n;
class item {
public:
	item() = default;
	int ar[SIZE][SIZE];
	item& operator *(const item &rhs);

};
item& item::operator *(const item &rhs)
{
	item temp;
	int i,j,k;
	for (i = 0; i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			temp.ar[i][j] = 0;
			for (k = 0;k < n;k++)
			{
				temp.ar[i][j] += ar[i][k] * rhs.ar[k][j];
			}
			temp.ar[i][j] %= MOD;
		}
	}
	return temp;
}
item ans,res;
void pow(int k)
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
			ans = ans * res;
		res = res * res ;
		k >>= 1;
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int i,j,k;
		cin >> n >> k;
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < n;j++)
			{
				cin >> res.ar[i][j];
			}
		}
		pow(k);
		int sum = 0;
		for (i = 0;i < n;i++)
			sum += ans.ar[i][i];
		printf("%d\n",sum % 9973);
	}
	return 0;
}
