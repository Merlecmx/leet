class Solution {
public:
    int findPairs(vector<int>& nums, int k)
    {
        if(k < 0 || nums.size() <= 1){
            return 0;
        }
        int count = 0;
        if (k == 0){
            map<int,int> mp;
            for (int i = 0;i < nums.size();i++){
                mp[nums[i]]++;
            }
            for (map<int,int>::iterator it = mp.begin();it != mp.end();it++)
            {
                if (it->second > 1)
                    count++;
            }
            return count;
        }
        else{
            set<int> res(nums.cbegin(),nums.cend());
            set<int>::iterator i;
            set<int>::iterator j;
            for (i = res.begin();i != res.end();i++)
            {
                for (j = ++i,i--;j != res.end();j++)
                {
                    if (abs(*i - *j) == k)
                        count++;
                }
            }
            return count;
        }
    }
};
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
