class Solution {
public:
    int fib(int N) {
        int ar[31];
        ar[0] = 0;
        ar[1] = 1;
        for (int i = 2;i <= N;i++)
        {
            ar[i] = ar[i-1] + ar[i-2];
        }
        return ar[N];
    }
};
