class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        long long int fir = LLONG_MIN,sec = LLONG_MIN,thi = LLONG_MIN;
        vector<int>::iterator it;
        for (it = nums.begin();it != nums.end();it++)
        {
            if (*it == fir || *it == sec || *it == thi)
                continue;
            if (*it > fir){
                thi = sec;
                sec = fir;
                fir = *it;
            }
            else if (*it >= sec){
                thi = sec;
                sec = *it;
            }
            else if (*it >= thi){
                thi = *it;
            }
        }
        return thi == LLONG_MIN ? fir : thi;
    }
};
