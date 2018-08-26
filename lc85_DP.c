int min(int a,int b){
    return a < b ? a : b;
}
int max(int a,int b){
    return a > b ? a : b;
}
int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize)
{
    int row = matrixRowSize,col = matrixColSize;
    int i,j,k;
    int maxarea = 0;
    int* left = (int*)malloc(sizeof(int)* col);
    int* right = (int*)malloc(sizeof(int)* col);
    int* height = (int*)malloc(sizeof(int)* col);
    for (i = 0;i < col;i++){
        left[i] = 0;
        right[i] = col;
        height[i] = 0;
    }
    
    for (i = 0;i < row;i++)
    {
        int leftbound = 0;
        int rightbound = col;
        for (j = 0;j < col;j++)
        {
            if (matrix[i][j] == '1')
            {
                height[j]++;
                left[j] = max(left[j],leftbound);
            }
            else
            {
                height[j] = 0;
                left[j] = 0;
                leftbound = j + 1;
            }
        }
        
        for (k = col-1;k >= 0;k--)
        {
            if (matrix[i][k] == '1')
            {
                right[k] = min(right[k],rightbound);
            }
            else
            {
                right[k] = col;
                rightbound = k;
            }
        }
        for (j = 0;j < col;j++)
        {
            maxarea = max(maxarea,height[j] * (right[j] - left[j]) );
        }
    }
    return maxarea;
}
