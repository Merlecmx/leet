class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1] = {0};   //dp[n] 表示 当数为n时，最大的乘积
        dp[1] = 0;
        dp[2] = 1;
        int i,j;
        for (i = 3;i <= n;i++) 
        {
            for (j = 1;j + j <= i;j++)
            {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i-j]));    // i拆分为 j 和 i-j
            }
        }
        for (i = 1;i <= n;i++)
            cout << dp[i] << endl;
        return dp[n];
    }
};
