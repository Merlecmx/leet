class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                                ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                                "...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int> mp;
        int i,j;
        string s;
        for (i = 0;i < words.size();i++)
        {
            s.clear();
            for (j = 0;j < words[i].size();j++)
            {
                char ch = words[i][j];
                s.append(morse[ch-'a']);
            }
            mp[s]++;
        }
        return mp.size();
    }
};
