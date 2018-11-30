class Solution {
public:
    bool buddyStrings(string A, string B) {
        int i,j;
        int flag = 0;
        for (i = 0;i < A.size();i++)
        {
            if (A[i] != B[i])
                break;
        }
        for (j = i+1;j < A.size();j++)
        {
            if (A[j] != B[j])
                break;
        }
        if (i == A.size())    //如果AB串相同 判断A是否有重复字符 
        {
            int* ar = new int[26];
            for (j = 0;j < A.size();j++) {
                if (ar[A[j] - 'a'])
                    return true;    //存在重复字符则 true 
                ar[A[j] - 'a'] = 1;
            }
            return false;
        }
        swap(A[i],A[j]);
        return A == B;
    }
};
