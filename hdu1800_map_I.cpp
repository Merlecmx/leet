#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int n;
	map<string,int> res;
	string s;
	int max_count = 1;
	while (cin >> n)
	{
		res.clear();
		max_count = 1;
		while (n--)
		{
			cin >> s;
			for (string::iterator its = s.begin(); *its == '0'; s.erase(its));
			pair<map<string,int >::iterator,bool> p = res.insert({s,1});
			if (!p.second)
			{
				++p.first->second;
				if (p.first->second > max_count)
					max_count = p.first->second;
			}
		}
		cout << max_count << endl;
	}
	return 0;
}
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
