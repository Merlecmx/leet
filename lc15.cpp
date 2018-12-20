class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ar;
        int i,left,right;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (i = 0;i < len -2;i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            left = i + 1;
            right = len - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    // vector<int> temp = {nums[i], nums[left], nums[right]};
                    ar.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (left < right && nums[left] == nums[left -1]) left++;
                    right--;
                    while (left < right && nums[right] == nums[right +1]) right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ar;
    }
};
