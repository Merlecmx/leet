class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int count = 1;
        int i,max_len = 0;
        for (i = 1;i < nums.size();i++)
        {
            if (nums[i] > nums[i-1])
            {
                count++;
            }
            else
            {
                max_len = max(max_len,count);
                count = 1;
            }
        }
        max_len = max(max_len,count);
        return max_len;
    }
};
