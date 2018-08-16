void merge(int* nums1, int m, int* nums2, int n)
{
    int i;
    int j = 0,k = 0;
    int *temp = (int*)malloc(sizeof(int)* m);
    for (i = 0;i < m;i++)
        temp[i] = nums1[i];
    i = 0;
    while (i < m && j < n)
    {
        if (temp[i] <= nums2[j])
            nums1[k++] = temp[i++];
        else
            nums1[k++] = nums2[j++];
    }
    while (i < m)
        nums1[k++] = temp[i++];
    while (j < n)
        nums1[k++] = nums2[j++];
    free(temp);
}
