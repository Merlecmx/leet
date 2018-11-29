class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0;
        for (int i = s.size()-1;i >= 0;i--)
        {
            if (s[i] == ' ') {
                if (n)
                    return n;
                else
                    continue;
            }
            n++;
        }
        return n;
    }
};
