class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() > b.size())
            return a.size();
        else if (a.size() < b.size())
            return b.size();
        else {
            if (a.compare(b))
                return a.size();
            else
                return -1;
        }
    }
};
