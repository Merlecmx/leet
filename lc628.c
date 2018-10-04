class Solution {
public:
    int Partition(vector<int>& ar,int low,int high)
    {
        int pivotkey = ar[low];
        while (low < high)
        {
            while (low < high && pivotkey <= ar[high])  high--;
            ar[low] = ar[high];
            while (low < high && pivotkey >= ar[low])  low++;
            ar[high] = ar[low];
        }
        ar[low] = pivotkey;
        return low;
    }
    void Qsort(vector<int>& nums,int low,int high)
    {
        if (low < high)
        {
            int k = Partition(nums,low,high);
            Qsort(nums,low,k-1);
            Qsort(nums,k+1,high);
        }
    }
    int maximumProduct(vector<int>& nums)
    {
        int t = nums.size()-1;
        Qsort(nums,0,t);
        //for (int i = 0;i < nums.size();i++)
            //cout << nums[i] << " ";
        //cout << "\n" << endl;
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
