class Solution {
public:
    int countSegments(string s) {
        if (s == "")
            return 0;
        int count = 0;
        int i;
        for (i = 0;i < s.size();i++)
        {
            while (s[i] == ' ')
                i++;
            while (i < s.size() && s[i] != ' ')
                i++;
            if (s[i] == ' ')
                count++;
        }
        count += s[s.size()-1] != ' ';
        return count;
    }
};
