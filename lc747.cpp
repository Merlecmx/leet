class Solution {
public:
    int dominantIndex(vector<int>& nums)
    {
        int max = INT_MIN;
        int i,id = -1;
        for (i = 0;i < nums.size();i++)
        {
            if (nums[i] > max){
                max = nums[i];
                id = i;
            }
        }
        for (i = 0;i < nums.size();i++)
        {
            if (i == id)
                continue;
            if (max < nums[i] * 2)
                break;
        }
        return i == nums.size() ? id : -1;
    }
};
