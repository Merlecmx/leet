#define SIZE 26
bool isAnagram(char* s, char* t)
{
    int ar1[SIZE] = {0};
    int ar2[SIZE] = {0};
    while (*s)
    {
        ar1[*s-'a']++;
        s++;
    }
    while (*t)
    {
        ar2[*t - 'a']++;
        t++;
    }
    for (int i = 0;i < SIZE;i++)
    {
        if (ar1[i] != ar2[i])
            return false;
    }
    return true;
}
