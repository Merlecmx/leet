bool dp[600010][110];    // dp[i][j] ��ʾt����ǰi���Ӵ��Ƿ���Ա�Ϊ s����ǰj ���ַ�
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        int s_len = s.size();    // short
        int t_len = t.size();    // long
        for (i = 0,j = 1;j <= s_len;j++)
        {
            dp[i][j] = false;
        }
        for (i = 0,j = 0;i <= t_len;i++)
        {
            dp[i][j] = true;
        }
        for (i = 1;i <= t_len;i++)
        {
            for (j = 1;j <= s_len;j++)
            {
                if (i < j) {
                    for (int k = j;k < s_len;k++)
                        dp[i][k] = false;
                    break;
                }
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[t_len][s_len];
    }
};
