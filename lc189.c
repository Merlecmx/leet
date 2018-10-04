class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        if (k == 0 || nums.size() < 2 || k % nums.size() == 0)
            return ;
        //vector<int>::size_type len = nums.size();
        int len = nums.size();
        int count = 0;
        int i = 0,start = 0;
        int ele = nums[0];
        while (count < len)
        {
            if (i == start)
            {
                i++;
                start = i;
                ele = nums[i];
            }
            i = (i+k) % len;
            int temp = nums[i];
            nums[i] = ele;
            ele = temp;
            count++;
        }
    }
};
