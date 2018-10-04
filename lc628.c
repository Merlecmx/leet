class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
    	sort(nums.begin(),nums.end());
        int t = nums.size()-1;
        int target = 0;
        if (nums[t] > 0)
        {
            int a = nums[0] * nums[1];
            int b = nums[t-1] * nums[t-2];
            target =  nums[t] * (a > b ? a : b);
        }
        else
            target = nums[t] * nums[t-1] * nums[t-2];
        return target;
    }
};
