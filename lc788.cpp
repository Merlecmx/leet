class Solution {
public:
    int rotatedDigits(int N)
    {
        int i,count = 0;
        for (i = 1 ;i <= N;i++)
        {
            if (fun(i))
                count++;
        }
        return count;
    }
    bool fun(int n)
    {
        int flag = 0;
        while (n)
        {
            int t = n % 10;
            if (t == 3 || t == 4 || t == 7)
                return false;
            if (t == 2 || t == 5 || t == 6 || t == 9)
                flag = 1;
            n /= 10;
        }
        return flag;
    }
};
