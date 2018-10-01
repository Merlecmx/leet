/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    *returnSize = 2;
    int* ans = (int*)malloc(sizeof(int) * 2);
    int i,j;
    int A_sum = 0,B_sum = 0;
    for (i = 0;i < ASize;i++)
        A_sum += A[i];
    for (j = 0;j < BSize;j++)
        B_sum += B[j];
    int diff = A_sum - B_sum;
    int half = diff / 2;
    int flag = 0;
    for (i = 0;i < ASize;i++)
    {
        for (j = 0;j < BSize;j++)
        {
            if (A[i] - B[j] == half)
            {
                ans[0] = A[i];
                ans[1] = B[j];
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    return ans;
}
