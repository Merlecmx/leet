bool isMatch(char* s, char* p)
{
    int l_s1 = strlen(s);
    int l_s2 = strlen(p);
    
    int (*dp)[l_s2+1] = (int(*)[l_s2+1])malloc(sizeof(int)* (l_s1+1) * (l_s2+1));
    //memset(dp,0,sizeof(int)* (l_s1+1) * (l_s2+1));
    int i,j;
    dp[0][0] = 1;
    
    for (j = 1;j <= l_s2;j++){        //i == 0;
        if (p[j-1] == '*')
            dp[0][j] = dp[0][j-1];
    }
    for (i = 1;i <= l_s1;i++){        // p´® Îª¿Õ;
        dp[i][0] = 0;
    }
    
    for (i = 1;i <= l_s1;i++)
    {
        for (j = 1;j <= l_s2;j++)
        {
            if (s[i-1] == p[j-1] || p[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];
            else if (p[j-1] == '*')
            {
                for (int k = 0;k <= i;k++)
                {
                    if (dp[k][j-1] == 1){
                        dp[i][j] = 1;
                        break;
                    }
                }
            }
            else
                dp[i][j] = 0;
        }
    }
    return dp[l_s1][l_s2];
}
