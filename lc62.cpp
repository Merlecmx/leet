class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j;
        int dp[m+1][n+1];   // dp[i][j]��ʾi�� j�еĲ�ͬ·��
        for (i = 1,j = 1;j < n + 1;j++) {
            dp[i][j] = 1;
        }
        for (i = 1,j = 1;i < m + 1;i++) {
            dp[i][j] = 1;
        }
        for (i = 2;i < m + 1;i++)
        {
            for (j = 2;j < n + 1;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
