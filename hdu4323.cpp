#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int min_s(int a,int b,int c){
    if (a < b){
        if (c < a)
            return c;
        else
            return a;
    }
    else{
        if (c < b)
            return c;
        else
            return b;
    }
}
int minDistance(string word1, string word2)
{
    int len1 = word1.size();
    int len2 = word2.size();
    //int (*ar)[len2+1] = (int(*)[len2+1])malloc(sizeof(int)* (len1+1) * (len2+1));
    int ar[100][100];
    int i,j;
    for (i = 0;i <= len1;i++) {
        ar[i][0] = i;
    }
    for (j = 0;j <= len2;j++) {
        ar[0][j] = j;
    }
    for (i = 1;i <= len1;i++)
    {
        for (j = 1;j <= len2;j++)
        {
            if(word1[i-1] == word2[j-1])
                ar[i][j] = ar[i-1][j-1];
            else
            {
                ar[i][j] = min_s(ar[i-1][j], ar[i][j-1], ar[i-1][j-1]) + 1;
            }
        }
    }
    int t = ar[len1][len2];
    //free(ar);
    return t;
}
int main()
{
    int id,T;
    int sum[1002];
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
            cin >> s >> k;
            count = 0;
            for (j = 0;j < n;j++)
            {
                int t = minDistance(res[j],s);
                if (t <= k)
                    count++;
            }
            sum[i] = count;
        }
        
        cout << "Case #" << id << ":" << endl;
        for (i = 0;i < m;i++) {
            cout << sum[i] << endl;
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
