#define COL 50
char* largestNumber(int* nums, int numsSize)
{
    int i,j;
    char (*p)[COL] = (char(*)[COL])malloc(sizeof(char)* numsSize* COL);
    for (i = 0;i < numsSize;i++)
    {
        sprintf(p[i],"%d",nums[i]);
    }
    char* ar = (char*)malloc(sizeof(char) * 10000);
    char *temp = (char*)malloc(sizeof(char)* COL);
    char *str1 = (char*)malloc(sizeof(char)* COL);
    char *str2 = (char*)malloc(sizeof(char)* COL);
    int* visited = (int*)malloc(sizeof(int)* numsSize);
    memset(visited,0,sizeof(int)* numsSize);
    int count = 0;
    int k = 0;
    while (count < numsSize)
    {
        for (i = 0;visited[i];i++);
        strcpy(temp,p[i]);
        k = i;
        for (j = i+1;j < numsSize;j++)
        {
            if (!visited[j])
            {
                strcpy(str1,temp);
                strcpy(str2,p[j]);
                strcat(str1,p[j]);
                strcat(str2,temp);
                if (strcmp(str1,str2) < 0){
                    strcpy(temp,p[j]);
                    k = j;
                }
            }
        }
        strcat(ar,p[k]);
        visited[k] = 1;
        count++;
    }
    free(p);
    free(temp);
    free(str1);
    free(str2);
    int len = strlen(ar);
    for (i = 0;i < len;i++)
    {
        if (ar[i] != '0')
            break;
    }
    if (i == len)
        return "0";
    else
        return ar+i;
