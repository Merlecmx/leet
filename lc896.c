bool isMonotonic(int* A, int ASize)
{
    int i,j;
    for (i = 1;i < ASize && A[i] <= A[i-1];i++) ;
    if (i == ASize) return true;
    for (j = 1;j < ASize && A[j] >= A[j-1];j++) ;
    if (j == ASize) return true;

    return false;
}
