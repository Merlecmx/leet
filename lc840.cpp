class Solution {
public:
    bool fun(vector<vector<int>>& ar,int i,int j)
    {
        if (ar[i+1][j+1] != 5)
            return false;
        int x,y;
        int res1,res2;
        int sum = ar[i][j] + ar[i][j+1] + ar[i][j+2];
        for (x = i;x < i+3;x++)
        {
            res1 = 0;
            for (y = j;y < j+3;y++)
            {
                if (ar[x][y] < 1 || ar[x][y] > 9)
                    return false;
                res1 += ar[x][y];
            }
            if (res1 != sum)
                return false;
        }
        for (y = j;y < j+3;y++)
        {
            res2 = 0;
            for (x = i;x < i+3;x++)
            {
                if (ar[x][y] < 1 || ar[x][y] > 9)
                    return false;
                res2 += ar[x][y];
            }
            if (res2 != sum)
                return false;
        }
        res1 = ar[i][j] + ar[i+1][j+1] + ar[i+2][j+2];
        res2 = ar[i][j+2] + ar[i+1][j+1] + ar[i+2][j];
        if (res1 != sum || res2 != sum)
            return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int i,j;
        int count = 0;
        for (i = 0;i < row-2;i++)
        {
            for (j = 0;j < col-2;j++)
            {
                if (fun(grid,i,j)){
                    count++;
                    printf("Hello World!");
                }
            }
        }
        return count;
    }
};
