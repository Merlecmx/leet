#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int n,num;
	int max_count = 1;
	map<int,int> res;
	while (cin >> n)
	{
		res.clear();
		max_count = 1;
		while (n--)
		{
			scanf("%d",&num);
			res[num]++;
			if (res[num] > max_count)
				max_count = res[num];
		}
		cout << max_count << endl;
	}
	return 0;
}
