class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ar(rowIndex+1,1);
        int t,temp;
        for (int i = 1;i < rowIndex;i++)
        {
            t = 1;
            for (int j = 1;j <= i;j++)
            {
                temp = ar[j];
                ar[j] = t + ar[j];
                t = temp;
            }
            
        }
        return ar;
    }
};
