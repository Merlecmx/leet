class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int i,j;
        for (i = 1;i < A.size();i++)
        {
            if (A[i] < A[i-1]) 
                break;
        }
        if (i == 1 || i == A.size())
            return false;
        for (j = i;j < A.size();j++)
        {
            if (A[j] >= A[j-1])
                return false;
        }
        return true;
    }
};
