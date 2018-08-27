int min(int a,int b, int c){
    if (a < b){
        if (c < a)
            return c;
        else
            return a;
    }
    else{
        if (c < b)
            return c;
        else
            return b;
    }
}
int minDistance(char* word1, char* word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int (*ar)[len2+1] = (int(*)[len2+1])malloc(sizeof(int)* (len1+1) * (len2+1));
    int i,j;
    for (i = 0;i <= len1;i++){
        ar[i][0] = i;
    }
    for (j = 0;j <= len2;j++){
        ar[0][j] = j;
    }
    for (i = 1;i <= len1;i++)
    {
        for (j = 1;j <= len2;j++)
        {
            if(word1[i-1] == word2[j-1])
                ar[i][j] = ar[i-1][j-1];
            else
            {
                ar[i][j] = min(ar[i-1][j],ar[i][j-1],ar[i-1][j-1]) + 1;
            }
        }
    }
    return ar[len1][len2];
}
