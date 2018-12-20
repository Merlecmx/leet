class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        int dp[len][len];
        int i,j;
        for (i = 0;i < len;i++)
        {
            dp[i][i] = piles[i];
        }
        for (i = len-1;i >= 0;i--)
        {
            for (j = i + 1;j < len;j++)
            {
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][len-1] > 0;
    }
};
