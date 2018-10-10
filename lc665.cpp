class Solution {
public:
    bool checkPossibility(vector<int>& nums)
    {
        if (nums.size() == 1)
            return true;
        int count = 0;
        if (nums[0] > nums[1]){
            count++;
        }
        int i;
        for (i = 2;i < nums.size();i++)
        {
            if (nums[i] < nums[i-1])
            {
                count++;
                if (count == 2)
                    return false;
                if (nums[i] > nums[i-2])
                    nums[i-1] = nums[i-2];
                else
                    nums[i] = nums[i-1];
            }
        }
        return true;
    }
};
