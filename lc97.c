bool isInterleave(char* s1, char* s2, char* s3)
{
    int l_s1 = strlen(s1);
    int l_s2 = strlen(s2);
    int l_s3 = strlen(s3);
    if (l_s1 + l_s2 != l_s3)
        return false;
    int i,j;
    int (*ar)[l_s2+1] = (int(*)[l_s2+1])malloc(sizeof(int)* (l_s1+1) * (l_s2+1));
    memset(ar,0,sizeof(int)* (l_s1+1) * (l_s2+1));
    ar[0][0] = 1;
    for (i = 1;i <= l_s1;i++)     // j == 0
    {
        if (s1[i-1] == s3[i-1])
            ar[i][0] = ar[i-1][0];
    }
    for (j = 1;j <= l_s2;j++)     // i == 0
    {
        if (s2[j-1] == s3[j-1])
            ar[0][j] = ar[0][j-1];
    }
    for (i = 1;i <= l_s1;i++)
    {
        for (j = 1;j <= l_s2;j++)
        {
            if (s1[i-1] == s3[i+j-1] && ar[i-1][j])
                ar[i][j] = ar[i-1][j];
            if (s2[j-1] == s3[i+j-1] && ar[i][j-1])
                ar[i][j] = ar[i][j-1];
        }
    }
    return ar[l_s1][l_s2];
}
