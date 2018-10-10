class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int count = 0;
        vector<int>::iterator it;
        for (it = flowerbed.begin();it < flowerbed.end();)
        {
            if (*it == 1)
                it += 2;
            else
            {
                if (it == flowerbed.begin() && *(it+1) == 0){
                    count++;
                    it += 2;
                    continue;
                }
                if (it == flowerbed.end()-1 && *(it-1) == 0){
                    count++;
                    it += 2;
                    continue;
                }
                if (it!= flowerbed.begin() && it != flowerbed.end() && *(it-1) == 0 && *(it+1) == 0){
                    count++;
                    it += 2;
                }
                else if (it!= flowerbed.begin() && *(it-1) == 1)
                    it++;
                else if (it != flowerbed.end() && *(it+1) == 1)
                    it += 3;
            }
        }
        return count >= n;
    }
};
