class Solution {
public:
    bool checkRecord(string s) {
        int count = 0;
        for (char ch :s)
        {
            if (ch == 'A')
                count++;
        }
        string::size_type pos = s.find("LLL");
        return count < 2 && pos == string::npos;
    }
};
