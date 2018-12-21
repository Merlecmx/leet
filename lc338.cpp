class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ar(num + 1);
        ar[0] = 0;
        ar[1] = 1;
        int i;
        for (i = 2;i <= num;i++)
        {
            ar[i] = ar[i/2] + (i & 1);
        }
        return ar;
    }
};
