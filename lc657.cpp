class Solution {
public:
    bool judgeCircle(string moves)
    {
        int* ar = new int[4];
        memset(ar,0,4 * sizeof(int));
        for (int i = 0;i < moves.size();i++)
        {
             if (moves[i] == 'U') ar[0]++;
             else if (moves[i] == 'D') ar[1]++;
             else if (moves[i] == 'L') ar[2]++;
             else ar[3]++;
        }
        return ar[0] == ar[1] && ar[2] == ar[3];
    }
};
