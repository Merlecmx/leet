class Solution {
public:
    string toLowerCase(string str)
    {
        for (auto &ch:str)
        {
            ch = tolower(ch);
        }
        return str;
    }
};
