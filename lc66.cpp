class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int flag = 1;
        int i;
        int t = digits.size()-1;
        for (i = t;i >= 0 && flag == 1;i--)
        {
            digits[i] = digits[i] + flag;
            if (digits[i] == 10){
                flag = 1;
                digits[i] = 0;
            }
            else{
                flag = 0;
            }
        }
        vector<int> ar;
        if (flag)
            ar.push_back(1);
        for (i = 0;i < digits.size();i++)
        {
            ar.push_back(digits[i]);
        }
        return ar;
    }
};
