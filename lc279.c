//  n = 4^a(8*b +7) 
int numSquares(int n)
{
    while (n % 4 == 0)
        n /= 4;
    if (n % 8 == 7)
        return 4;
    int k;
    for (k = 0;k * k < n;k++)
    {
        int t = sqrt(n - k*k);
        if (t*t + k*k == n)
            return 1 + !!k;
    }
    return 3;
}
