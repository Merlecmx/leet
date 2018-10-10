class Solution {
public:
    int gcd(int x, int y)   // �� x,y ���Լ��
    {
        if(y == 0)   return x;
        if(x < y)
            return gcd(y,x);
        else
            return gcd(y, x%y);
    }
    bool hasGroupsSizeX(vector<int>& deck)
    {
        map<int,int> mp;
        for (int i:deck)
        {
            mp[i]++;
        }
        int res = 0;
        for (auto k:mp)
        {
            res = gcd(k.second,res);
        }
        return res > 1;
    }
};
