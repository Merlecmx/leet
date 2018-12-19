class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int *ar = new int[n+1];
        ar[1] = 1;
        ar[2] = 2;
        for (int i = 3;i <= n;i++)
        {
            ar[i] = ar[i-1] + ar[i-2];
        }
        return ar[n];
    }
};
