int missingNumber(int* nums, int numsSize){
    int sum = (numsSize + 1)*numsSize/2;
    int s = 0;
    for(int i = 0; i < numsSize; i++)
    {
        sum-=nums[i];
    }
    return sum;
}
