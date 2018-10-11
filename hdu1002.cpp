#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	string s_a,s_b;
	cin >> n;
	int i,j,num;
	for (int k = 1;k <= n;k++)
	{
		s_a.clear();
		s_b.clear();
		cin >> s_a >> s_b;
		int lena = s_a.size();
		int lenb = s_b.size();
		int t = max(lena,lenb);
		string s(t,'\0');
		int flag = 0;
		for (t -= 1,i = lena-1,j = lenb-1;i >= 0 || j >= 0;i--,j--,t--)
		{
			if (i >= 0 && j >= 0){
				num = (s_a[i]-'0') + (s_b[j]-'0') + flag;
			}
			else if (i >= 0){
				num = s_a[i] - '0' + flag;
			}
			else{
				num = s_b[j] - '0' + flag;
			}
			if (num > 9){
				s[t] = num % 10 + '0';
				flag = num / 10;
			}
			else{
				s[t] = num + '0';
				flag = 0;
			}
		}
		if (flag){
			s = "1" + s;
		}
		size_t pos = s.find_first_not_of("0");
		if (pos !=string::npos)
			s = s.substr(pos);
		else{
			s.clear();
			s += "0";
		}
		printf("Case %d:\n",k);
		cout << s_a << " + " << s_b << " = " << s;
		printf("\n");
		if (k < n) printf("\n");
	}
	return 0;
}
