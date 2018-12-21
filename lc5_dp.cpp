int dp[1002][1002];
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        int len = s.size();
//        int dp[len][len];
        int i,j,left = 0;
        int max_len = 1;
        for (i = 0;i < len;i++) {
            dp[i][i] = 1;
        }
        for (i = len - 1;i >= 0;i--)
        {
            for (j = i + 1;j < len;j++)
            {
                if (s[i] == s[j]) {
                    if (i == j - 1) {
                        dp[i][j] = 1;
                        if (j - i + 1 > max_len) {
                            left = i;
                            max_len = j - i + 1;
                        }
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                        if (dp[i][j] == 1 && j - i + 1 > max_len) {
                            left = i;
                            max_len = j - i + 1;
                        }
                    }
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return s.substr(left, max_len);
    }
};
