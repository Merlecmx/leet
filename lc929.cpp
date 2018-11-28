class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int i,j;
        map<string,int> mp;
        string s;
        for (i = 0;i < emails.size();i++)
        {
            s.clear();
            int k = 0;
            for (j = 0; emails[i][j] != '@'; j++)
            {
                char ch = emails[i][j];
                if (ch == '+' || ch == '.')
                {
                    s.append(emails[i].begin()+k,emails[i].begin()+j);
                    k = j+1;
                    if (ch == '+')
                        break;
                }
            }
            j = emails[i].find('@');
            s.append(emails[i].begin()+j,emails[i].end());
            mp[s]++;
        }
        return mp.size();
    }
};
