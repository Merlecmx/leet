class Solution {
public:
    bool onecount(string& s)
    {
        int count = 0;
        for (int i = 0;i < s.size();i++)
        {
            if (s[i] != '1' && s[i] != '0')
                return false;
            if (s[i] == '1')
                count++;
        }
        return count == 1;
    }
    bool isHappy(int n)
    {
        string s;
        map<int,int> mp;
        while (n > 0)
        {
            s.clear();
            mp[n]++;
            s = to_string(n);
            if (onecount(s)){
                return true;
            }
            else
            {
                n = 0;
                for (int i = 0;i < s.size();i++)
                {
                    n += (s[i]-'0') * (s[i]-'0');
                }
            }
            if (mp[n])
                return false;
        }
        return false;
    }
};
