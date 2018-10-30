class Solution {
public:
    string reverseString(string s) {
        //reverse(s.begin(),s.end());
        //return s;
        string::iterator left,right;
        for (left = s.begin(),right = s.end()-1;left < right;left++,right--)
        {
            swap(*left,*right);
        }
        return s;
    }
};
