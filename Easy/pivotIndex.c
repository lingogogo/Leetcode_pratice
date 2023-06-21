int pivotIndex(int* nums, int numsSize){
    int* left_sum = malloc(sizeof(int)*numsSize );
    int* right_sum = malloc(sizeof(int)*numsSize );
    left_sum[0] = nums[0];
    if(numsSize == 1) return 0;

    right_sum[numsSize - 1] = nums[numsSize-1];
    for(int i = numsSize - 2; i >= 0;i--)
    {
        right_sum[i] = right_sum[i + 1] + nums[i]; 
        
    }
    if(right_sum[1] == 0)
        return 0;
    
    for(int i= 1; i < numsSize;i++)
    {
        left_sum[i] = left_sum[i - 1] + nums[i]; 
        if(i > 1 && right_sum[i] == left_sum[i - 2])
            return (i - 1);
    }
    if(left_sum[numsSize - 2] == 0)
        return numsSize - 1;
    else 
        return -1;

}

/*

int pivotIndex(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int s = 0;
    for (int i = 0; i < numsSize; i++) {
        
        if (2*s == (sum - nums[i])) {
            return i;
        }
        s += nums[i];
        
    }
    return -1;
}

*/
