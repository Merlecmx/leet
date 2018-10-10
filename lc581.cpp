class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> ar(nums);
        sort(ar.begin(),ar.end());
        int i;
        int left = -1,right = -2;
        for (i = 0;i < ar.size();i++)
        {
            if (ar[i] != nums[i] && left == -1)
                left = i;
            if (ar[i] != nums[i] && left != -1)
                right = i;
        }
        return right - left +1;
    }
};
