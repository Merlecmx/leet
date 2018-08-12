// δAC 
int S_cmp(const void *a,const void *b)
{
    return strcmp((char*)a, (char*)b);
}
#define COL 50
char* largestNumber(int* nums, int numsSize)
{
    char (*p)[COL] = (char(*)[COL])malloc(sizeof(char)* numsSize* COL);
    int i;
    for (i = 0;i < numsSize;i++)
    {
        sprintf(p[i],"%d",nums[i]);
        printf("%s  ",p[i]);
    }
    printf("\n");
    qsort(p,numsSize,sizeof(p[0]),S_cmp);
    
    for (int k = 0;k < numsSize;k++){
    printf("%s  ",p[k]);
    }
    printf("\n");
    
    char* ar = (char*)malloc(sizeof(char) * 10000);
    for (i = 0;i < numsSize;i++)
    {
        strcat(ar,p[i]);
    } 
    int len = strlen(ar);
    for (i = 0;i < len;i++)
    {
        if (ar[i] != '0')
            break;
    }
    if (i == len)
        return "0";
    else
    {
        strcpy(ar,ar+i);
    }
    return ar;
}
