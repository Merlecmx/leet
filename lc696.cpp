class Solution {
public:
    int countBinarySubstrings(string s) {
        int* ar = new int[50000];
        int count = 1;
        int i = 0,j;
        for (j = 1;j < s.size();j++)
        {
            if (s[j] == s[j-1])
                count++;
            else {
                ar[i++] = count;
                count = 1;
            }
        }
        ar[i++] = count;
        int sum = 0;
        while (--i)
        {
            sum += min(ar[i],ar[i-1]);
        }
        delete []ar;
        return sum;
    }
};
