int dp[10000][10000];
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        int len = A.size();
        cout << len << endl;
        // int dp[len][len];
        int i,j;
        int max_count = 0;
        for (i = 0;i < len-2;i++)
        {
            dp[i][i+2] = (A[i+1] - A[i] == A[i+2] - A[i+1]);
            max_count += dp[i][i+2];
        }
        cout << max_count << endl;
        for (i = len - 1;i >= 0;i--)
        {
            for (j = i + 3;j < len;j++)
            {
                if (dp[i+1][j] && (A[i+1] - A[i] == A[i+2] - A[i+1])) {
                    dp[i][j] = 1;
                    max_count += 1;
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return max_count;
    }
};
