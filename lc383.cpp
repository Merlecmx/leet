class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> ar;
        int i;
        for (i = 0;i < magazine.size();i++)
        {
            ar[magazine[i]]++;
        }
        map<char,int> ar2;
        for (i = 0;i < ransomNote.size();i++)
        {
            ar2[ransomNote[i]]++;
        }
        map<char,int>::iterator it;
        // for (auto &it : ar2)
        for (it = ar2.begin();it != ar2.end();it++)
        {
            //if (it.second > ar[it.first])
            if (it->second > ar[it->first])
                return false;
        }
        return true;
    }
};
