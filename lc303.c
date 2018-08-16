typedef struct {
    int* sum;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray*));
    obj->sum = (int*)malloc(sizeof(int)* (numsSize+1));
    obj->sum[0] = 0;
    int i;
    for (i = 0;i < numsSize;i++)
    {
        obj->sum[i+1] = obj->sum[i] + nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return (obj->sum[j+1] - obj->sum[i]);
}

void numArrayFree(NumArray* obj) {
    free(obj->sum);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
