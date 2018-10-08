class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> dp;
        dp.push_back(cost[0]);
        dp.push_back(cost[1]);
        int i;
        for (i = 2;i < cost.size();i++)
        {
            dp.push_back(cost[i] + min(dp[i-1],dp[i-2]));
        }
        return min(dp[i-2],dp[i-1]);
    }
};
