class Solution {
public:
    int romanToInt(string s) {
        int i,sum = 0;
        for (i = s.size()-1;i >= 0;i--)
        {
            if (s[i] == 'I')
                sum += sum < 5 ? 1 : -1;
            else if (s[i] == 'V')
                sum += 5;
            else if (s[i] == 'X')
                sum += sum < 50 ? 10 : -10;
            else if (s[i] == 'L')
                sum += 50;
            else if (s[i] == 'C')
                sum += sum < 500 ? 100 : -100;
            else if (s[i] == 'D')
                sum += 500;
            else 
                sum += 1000;
        }
        return sum;
    }
};
