class Solution
{
	public:
		int min(int a,int b)
		{
			return a < b ? a : b;
		}
		int max(int a,int b)
		{
			return a > b ? a : b;
		}
		vector<vector<int>> imageSmoother(vector<vector<int>>& M)
		{
			int row = M.size();
			int col = M[0].size();
			vector<vector<int>> ar(row,vector<int>(col));
			int i,j,x,y;
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
				{
					int sum = 0;
					int count = 0;
					int rows = min(row-1,i+1);
					for (x = max(0,i-1); x <= rows; x++)
					{
						int cols = min(col-1,j+1);
						for (y = max(0,j-1); y <= cols; y++)
						{
							sum += M[x][y];
							count++;
						}
					}
					ar[i][j] = sum / count;
				}
			}
			return ar;
		}
};
