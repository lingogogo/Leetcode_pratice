/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// learn how to use hashtable
struct hashtable
{
    int value;
    int cnt;
};
int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}
int cmph(const void *a, const void *b)
{
    return ((struct hashtable *)b)->cnt - ((struct hashtable *)a)->cnt;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    // k return number.
    if(k == 0 || numsSize == 0){
        *returnSize = k;
        return 0;
    }
    if (numsSize < k){
        *returnSize = 0;
        return 0;
    }
    if(numsSize == k && k == 1){
        *returnSize = 1;
        return nums;    
    }
    *returnSize = k;
    int* array = (int*)malloc(sizeof(int)*k);
    struct hashtable hash[numsSize];
    //set all hash number is zero
    memset(hash,0,sizeof(struct hashtable)*numsSize);
    int i;
    int count=1;

    qsort(nums, numsSize,sizeof(int),cmp);
    hash[0].value=nums[0];
    hash[0].cnt++;

    for (i=1;i<numsSize;i++){
        if(hash[count-1].value == nums[i]){
            hash[count-1].cnt++;
        } else {
            count++;
            hash[count-1].value = nums[i];
            hash[count-1].cnt++;
        }
    }

    qsort(hash, count,sizeof(hash[0]),cmph);

    for(i=0;i<k;i++){
        array[i] = hash[i].value;
    }
    
    return array;

}
