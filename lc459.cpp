class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        if (size < 2)
            return false;
        int i,id;
        for (i = 2;i <= size;i++)
        {
            if (size % i != 0)
                continue;
            for (id = 0;id + size/i < size;id++)
            {
                if (s[id] != s[id + size/i])
                    break;
            }
            if (id + size/i == size)
                return true;
        }
        return false;
    }
};
