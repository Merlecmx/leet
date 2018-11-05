class Solution {
public:
    string reverseWords(string s) {
        string::iterator left = s.begin();
        string::iterator right = s.begin();
        for ( ; right < s.end(); right++)
        {
            if (*right == ' '){
                reverse(left,right);
                left = right+1;
            }
        }
        reverse(left,right);
        return s;
    }
};
