class Solution {
public:
    int firstUniqChar(string s) {
        int* hash = (int*)malloc(sizeof(int) * 26);
        memset(hash, 0, sizeof(int) * 26);
        int i;
        for (i = 0;i < s.size();i++)
        {
            hash[s[i]-'a']++;
        }
        int t = -1;
        for (i = 0;i < s.size();i++)
        {
            if (hash[s[i]-'a'] == 1)
            {
                t = i;
                break;
            }
        }
        free(hash);
        return t;
    }
};
