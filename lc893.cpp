class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<map<char,int> > res;
        int i,j;
        for (auto &s : A)
        {
            map<char,int> char_count;
            for (i = 0;i < s.size();i += 2) {
                char_count[s[i]]++;
            }
            for (j = 1;j < s.size();j += 2) {
                char_count[s[j] - 32]++;     //����λ���ַ�ת��Ϊ��д
            }
            res.insert(char_count);
        }
        return res.size();
    }
};
