//   每个数都可以看成一个普通数 + 一个完美平方数;
int min(int a,int b)
{
    return a < b ? a : b;
}
int numSquares(int n)
{
    int* dp = (int*)malloc(sizeof(int) * (n+1));
    int i,j;
    for (i = 0;i <= n;i++)
        dp[i] = INT_MAX;
    for (i = 1;i * i <= n;i++)
        dp[i * i] = 1;
    for (i = 1;i <= n;i++)
    {
        for (j = 1;i + j*j <= n;j++)
        {
            dp[i + j*j] = min(dp[i] + 1,dp[i + j*j]);
        }
    }
    return dp[n];
}
