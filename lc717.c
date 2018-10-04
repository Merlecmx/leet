class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int len = bits.size();
        int i;
        for (i = 0;i < len-2;)
        {
            if (bits[i] == 0)
                i++;
            else
                i += 2;
        }
        if (i == len-1)
            return true;
        else
        {
            if (bits[i] == 0)
                return true;
            return false;
        }
    }
};
