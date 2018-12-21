class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int len = prices.size();
        int sell_dp[len];    // δ���й�Ʊ�������
        int hold_dp[len];    // ���й�Ʊ�������
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
    // δ���й�Ʊ��״̬��������������ֿ��ܡ�һ��������һ������δ���У�����������й�Ʊ����������
    // ���й�Ʊ��״̬���������Ҳ�����ֿ��ܡ�һ��������һ�����й�Ʊ��������������ǰδ���У���Ϣһ�죩���칺��
};
