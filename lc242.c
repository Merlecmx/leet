#define SIZE 26
bool isAnagram(char* s, char* t)
{
    char* str1 = s;
    char* str2 = t;
    int* ar1 = (int*)malloc(sizeof(int)* SIZE);
    int* ar2 = (int*)malloc(sizeof(int)* SIZE);
    memset(ar1,0,sizeof(int)* SIZE);
    memset(ar2,0,sizeof(int)* SIZE);
    while (*str1)
    {
        ar1[*str1-'a']++;
        str1++;
    }
    while (*str2)
    {
        ar2[*str2 - 'a']++;
        str2++;
    }
    for (int i = 0;i < SIZE;i++)
    {
        if (ar1[i] != ar2[i])
            return false;
    }
    return true;
}
