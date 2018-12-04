class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int* nextar = next(needle);
        int i = 0,j = 0;
        int hay_len = haystack.size();
        int nee_len = needle.size();
        while (i < hay_len && j < nee_len)
        {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = nextar[j];
            }
        }
        free(nextar);
        return j >= nee_len ? i - nee_len : -1;
    }
    int* next(const string &s) {
        int* ar = new int[s.size()+1];
        ar[0] = -1;
        int i = 0,j = -1;
        while (i < s.size())
        {
            if (j == -1 || s[i] == s[j]) {
                i++;
                j++;
                if (s[i] != s[j])
                    ar[i] = j;
                else
                    ar[i] = ar[j];
            }
            else {
                j = ar[j];
            }
        }
        return ar;
    }
};
