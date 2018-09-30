int Partition(int* ar,int low,int high)
{
    int pivotkey = ar[low];
    while (low < high)
    {
        while (low < high && pivotkey <= ar[high])  high--;
        ar[low] = ar[high];
        while (low < high && pivotkey >= ar[low])  low++;
        ar[high] = ar[low];
    }
    ar[low] = pivotkey;
    return low;
}
void Qsort(int* ar,int low,int high)
{
     if (low < high)
     {
         int k = Partition(ar,low,high);
         Qsort(ar,low,k-1);
         Qsort(ar,k+1,high);
     }
}
void dfs_backtrack(int* nums,int numsSize,int* returnSize,int** ar,int* temp,int idex,int* flag)
{
    if (idex == numsSize)
    {
        ar[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy(ar[*returnSize],temp,sizeof(int) * numsSize);
        (*returnSize)++;
        return ;
    }
    for (int i = 0;i < numsSize;i++)
    {
        if (i > 0 && nums[i] == nums[i-1] && !flag[i-1])
            continue;
        if (!flag[i]){
            temp[idex] = nums[i];
            flag[i] = 1;
            dfs_backtrack(nums,numsSize,returnSize,ar,temp,idex+1,flag);
            flag[i] = 0;
        }
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize)
{
    Qsort(nums,0,numsSize-1);
    *returnSize = 0;
    int** ar = (int**)malloc(sizeof(int*) * 10000);
    int* temp = (int*)malloc(sizeof(int) * numsSize);
    int* flag = (int*)malloc(sizeof(int) * numsSize);
    memset(flag,0,sizeof(int) * numsSize);
    
    dfs_backtrack(nums,numsSize,returnSize,ar,temp,0,flag);
    ar = (int**)realloc(ar,sizeof(int*) * (*returnSize));
    free(temp);
    free(flag);
    
    return ar;
}
bool fun2(double a,double b)
{
    if (fabs(a + b - 24) < 0.0001 || fabs(a - b - 24) < 0.0001 || fabs(a*b - 24) < 0.0001 || b && fabs(a/b - 24) < 0.0001)
    {
        //printf("%lf %lf\n",a,b);
        //printf("%lf\n",fabs(a*b - 24));
        return true;
    }
    return false;
}
bool fun1(double a,double b,double c)
{
    if (fun2(a+b,c) || fun2(a-b,c) || fun2(a*b,c) ||  b && fun2(a/b,c)) {printf("4\n");return true;}
    if (fun2(a,b+c) || fun2(a,b-c) || fun2(a,b*c) ||  c && fun2(a,b/c)) {printf("5");return true;}
    return false;
}
bool fun(double a,double b,double c,double d)
{
    if (fun1(a+b,c,d) || fun1(a-b,c,d) || fun1(a*b,c,d) || fun1(a/b,c,d)) {printf("1");return true;}
    if (fun1(a,b+c,d) || fun1(a,b-c,d) || fun1(a,b*c,d) || fun1(a,b/c,d)) {printf("2");return true;}
    if (fun1(a,b,c+d) || fun1(a,b,c-d) || fun1(a,b,c*d) || fun1(a,b,c/d)) {printf("3");return true;}
    return false;
}
bool judgePoint24(int* nums, int numsSize)
{
    int i;
    int size = 0;
    int** ar = permuteUnique(nums,numsSize,&size);
    for (i = 0;i < size;i++)
    {
        double a = (double)ar[i][0];
        double b = (double)ar[i][1];
        double c = (double)ar[i][2];
        double d = (double)ar[i][3];
        if (fun(a,b,c,d))
            return true;
    }
    return false;
}
