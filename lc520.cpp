class Solution {
public:
    bool detectCapitalUse(string word)
    {
        // string s1("abcdefghijklmnopqrstuvwxyz");
        // string s2("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        // string::size_type pos1 = 0,pos2 = 0,pos3 = 0;
        // if (isupper(word[0]))
        // {
        //     pos1 = word.find_first_of(s1,1);
        //     pos2 = word.find_first_of(s2,1);
        // }
        // else
        // {
        //     pos3 = word.find_first_of(s2);
        // }
        // if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos)
        //         return true;
        // return false;
        int i = 0,j;
        if (isupper(word[i]))
        {
            i++;
            if (i < word.size() && isupper(word[i])){
                for (j = i+1;j < word.size();j++)
                {
                    if (islower(word[j]))
                        return false;
                }
            }
            if (i < word.size() && islower(word[i])){
                for (j = i+1;j < word.size();j++)
                {
                    if (isupper(word[j]))
                        return false;
                }
            }
        }
        else
        {
            for (j = i+1;j < word.size();j++)
            {
                if (isupper(word[j]))
                    return false;
            }
        }
        return true;
    }
};
