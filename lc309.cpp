class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int len = prices.size();
        int sell_dp[len];    // 未持有股票最大利润
        int hold_dp[len];    // 持有股票最大利润
        sell_dp[0] = 0;
        hold_dp[0] = -prices[0];
        int i;
        for (i = 1;i < len;i++)
        {
            sell_dp[i] = max(sell_dp[i-1], hold_dp[i-1] + prices[i]);
            if (i > 1) {
                hold_dp[i] = max(hold_dp[i-1], sell_dp[i-2] - prices[i]);
            }
            else {
                hold_dp[i] = max(hold_dp[i-1], -prices[i]);
            }
        }
        return sell_dp[len - 1];
    }
    // 未持有股票的状态，最大利润有两种可能。一，和昨天一样保持未持有；二，昨天持有股票今天卖掉。
    // 持有股票的状态，最大利润也有两种可能。一，和昨天一样持有股票不卖；二，两天前未持有（休息一天）今天购买。
};
