class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() == 0) return true;
        char* ar = new char[5000];
        int i = 0,j;
        ar[i++] = s[0];
        for (j = 1;j < s.size();j++)
        {
            if (s[j] == ')' && ar[i-1] == '(' || s[j] == '}' && ar[i-1] == '{' || s[j] == ']' && ar[i-1] == '[')
                i--;
            else
                ar[i++] = s[j];
        }
        delete []ar;
        return i == 0;
    } 
};
