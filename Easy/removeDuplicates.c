int removeDuplicates(int* nums, int numsSize){
    int num = -101, con = 0;

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] > num)
        {
            num = nums[i];
            nums[con] = nums[i];
            con++;
        }
    }
    return con;
}
