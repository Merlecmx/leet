class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        if (k < 0 || nums.size() < 2)
            return 0;
        sort(nums.begin(),nums.end());
        vector<int>::iterator it;
        int count = 0;
        for (int i = 0;i < nums.size();i++)
        {
            int t = nums[i] + k;
            it = lower_bound(nums.begin()+i+1,nums.end(),t);
            if (it != nums.end() && *it == t)
                count++;
            while (i+1 < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return count;
    }
};
