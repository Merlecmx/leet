class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        vector<int> ar;
        int i,sum = 0;
        for (i = 0;i < k-1;i++)
        {
            ar.push_back(0);
            sum += nums[i];
        }
        sum += nums[i];
        ar.push_back(sum);
        int maxsum = sum;
        for (i++;i < nums.size();i++)
        {
            int t = ar[i-1] - nums[i-k] + nums[i];
            ar.push_back(t);
            if (t > maxsum)
                maxsum = t;
        }
        return  (double)maxsum / (double)k;
    }
};
