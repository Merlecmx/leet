class Solution {
public:
    int findShortestSubArray(vector<int>& nums)
    {
        vector<int> hash(50001,0);
        vector<int> id(50001,0);
        int i;
        int minlen = 50001,count = 1;
        for (i = 0;i < nums.size();i++)
        {
            if (hash[nums[i]] == 0)
            {
                hash[nums[i]]++;
                id[nums[i]] = i;
            }
            else
            {
                hash[nums[i]]++;
                if (hash[nums[i]] == count){
                    int temp = i - id[nums[i]] + 1;
                    if (temp < minlen){
                        minlen = temp;
                    }
                }
                else if (hash[nums[i]] > count){
                    minlen = i - id[nums[i]] + 1;
                    count = hash[nums[i]];
                }
            }
        }
        if (count == 1) return 1;
        return minlen;
    }
};
