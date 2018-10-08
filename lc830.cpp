class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        vector<vector<int>> ar;
        int i,left = 0;
        int count = 1;
        for (i = 1;i < S.size();i++)
        {
            if (S[i] == S[i-1])
            {
                count++;
            }
            else
            {
                if (count > 2){
                    ar.push_back({left,i-1});
                }
                left = i;
                count = 1;
            }
        }
        if (count > 2){
            ar.push_back({left,i-1});
        }
        return ar;
    }
};
