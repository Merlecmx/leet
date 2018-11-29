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
            string& temp = emails[i];
            for (j = 0; temp[j] != '@'; j++)
            {
                char ch = temp[j];
                if (ch == '+' || ch == '.')
                {
                    s.append(temp.begin() + k, temp.begin() + j);
                    k = j + 1;
                    if (ch == '+')
                        break;
                }
            }
            j = temp.find('@');
            s.append(temp.begin()+j, temp.end());
            mp[s]++;
        }
        return mp.size();
    }
};
