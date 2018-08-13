struct object{
       char buf[16];
};
int cmp(const void *a,const void *b)
{
    char s1[32];
    char s2[32];
    s1[0] = '\0';
    s2[0] = '\0';
    strcat(s1,((struct object*)a)->buf);
    strcat(s1,((struct object*)b)->buf);
    strcat(s2,((struct object*)b)->buf);
    strcat(s2,((struct object*)a)->buf);
    return strcmp(s1, s2);
}
char* largestNumber(int* nums, int numsSize)
{
    struct object* p = (struct object*)malloc(sizeof(struct object)* numsSize);
    int i;
    for (i = 0;i < numsSize;i++)
    {
        sprintf(p[i].buf,"%d",nums[i]);
    }
    qsort(p,numsSize,sizeof(struct object),cmp);
    
    if (p[numsSize-1].buf[0] == '0')
        return "0";
    char* ar = (char*)malloc(sizeof(char) * 1000);
    ar[0] = '\0';
    for (i = numsSize-1;i >= 0;i--)
    {
        strcat(ar,p[i].buf);
    }
    free(p);
    return ar;
}
    
