class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        if (!nums.size())
            return -1;
        vector<int> sum1(nums.size());
        vector<int> sum2(nums.size());
        sum1[0] = nums[0];
        sum2[nums.size()-1] = nums[nums.size()-1];
        int i;
        for (i = 1;i < nums.size();i++)
        {
            sum1[i] = sum1[i-1] + nums[i];
        }
        for (i = nums.size()-2;i >= 0;i--)
        {
            sum2[i] = sum2[i+1] + nums[i];
        }
        for (i = 0;i < nums.size();i++)
        {
            if (sum1[i] == sum2[i])
                return i;
        }
        return -1;
    }
};
