#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int minDistance(string &word1, string &word2)
{
    int ar[100][100];
    int i,j;
    for (i = 0;i <= word1.size();i++) {
        ar[i][0] = i;
    }
    for (j = 0;j <= word2.size();j++) {
        ar[0][j] = j;
    }
    for (i = 1;i <= word1.size();i++)
    {
        for (j = 1;j <= word2.size();j++)
        {
            if(word1[i-1] == word2[j-1])
                ar[i][j] = ar[i-1][j-1];
            else
            {
                ar[i][j] = min(min(ar[i-1][j], ar[i][j-1]), ar[i-1][j-1]) + 1;
            }
        }
    }
    return ar[word1.size()][word2.size()];
}
int main()
{
    int id,T;
    cin >> T;
    for (id = 1;id <= T;id++)
    {
        int i,j;
        int n,m;
        cin >> n >> m;
        vector<string> res(n);
        for (i = 0;i < n;i++)
        {
            cin >> res[i];
        }
        
        string s;
        int k,count;
        for (i = 0;i < m;i++)
        {
            cout << "Case #" << id << ":" << endl;
            cin >> s >> k;
            count = 0;
            for (j = 0;j < n;j++)
            {
                int t = minDistance(res[j],s);
                count += t <= k;
            }
            cout << count << endl;
        }
    }
    return 0;
}
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
