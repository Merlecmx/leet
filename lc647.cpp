int dp[1002][1002];
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty())
            return 0;
        int len = s.size();
        int i,j;
        int max_count = 0;
        for (i = 0;i < len;i++) {
            dp[i][i] = 1;
        }
        max_count += len;
        cout << max_count << endl;
        for (i = len - 1;i >= 0;i--)
        {
            for (j = i + 1;j < len;j++)
            {
                if (s[i] == s[j]) {
                    if (i == j - 1) {
                        dp[i][j] = 1;
                        max_count++;
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                        max_count += dp[i][j];
                    }
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return max_count;
    }
};
