class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int left = 0,result = 0;
        int i;
        int count = 0,max_len = 0;
        for (i = 0;i < seats.size();i++)
        {
            if (seats[i] == 0)
                count++;
            else{
                if (count > max_len){
                    result = (i-left) / 2;
                    max_len = count;
                }
                left = i;
                count = 0;
            }
        }
        if (seats[0] == 0)
        {
            for (count = 0,i = 0;seats[i] == 0;i++)
                count++;
        }
        result = max(result,count);
        if (seats[seats.size()-1] == 0)
        {
            for (count = 0,i = seats.size()-1;seats[i] == 0;i--)
                count++;
        }
        result = max(result,count);
        return result;
    }
};
