class Solution {
public:
    string toGoatLatin(string S) {
        string str;
        int i,j;
        int n = 1;     //第几个单词
        for (i = 0,j = 0;i < S.size()+1; i++)
        {
            if (S[i] == ' ' || i == S.size())
            {
                cout << i << " ";
                if (!judge(S[j]) ) {    //判断单词的首个字符是否为元音
                    rotate(S.begin() + j, S.begin() + j +1, S.begin() + i);       // ratate循环左移一位
                }
                str.append(S.begin() + j,S.begin() + i);
                str.append("ma");
                str.append(n,'a');
                if (i != S.size()) str.append(" ");
                n++;
                j = i + 1;
            }
        }
        return str;
    }
    bool judge(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
};
