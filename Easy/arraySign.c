int arraySign(int* nums, int numsSize){
    if(nums[0] == 0)
        return 0;
    int product_sum = nums[0];
    
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i]>0)
            product_sum *= 1;
        else if(nums[i]<0)
            product_sum *= -1;
        if(product_sum == 0 || nums[i]==0)
            return 0;
    }
    if(product_sum > 0)
        return 1;
    else
        return -1;
}
