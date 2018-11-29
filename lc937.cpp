bool cmp(const pair<string, string>& a, const pair<string, string>& b) {
    return a.second < b.second;
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int i,j;
        vector<pair<string,string>> res;
        vector<string> number;
        for (auto log : logs)
        {
            if (islower(log.back()) ) {
                for (i = 0;log[i] != ' ';i++) ;
                res.push_back(make_pair(log,log.substr(i+1)));
            }
            else {
                number.push_back(log);
            }
        }
        // for (i = 0;i < res.size();i++) {
        //     cout << res[i].first << " " << res[i].second << endl << endl;
        // }
        sort(res.begin(),res.end(),cmp);
        vector<string> result;
        for (i = 0;i < res.size();i++) {
            result.push_back(res[i].first);
        }
        for (i = 0;i < number.size();i++) {
            result.push_back(number[i]);
        }
        return result;
    }
};
