void moveZeroes(int* nums, int numsSize){
    int i = 0;
    int decrease = 0;
    while(i < (numsSize - decrease))
    {
        if(nums[i] == 0)
        {
            int con = i;
            decrease++;
            while(con < (numsSize - 1))
            {
                int temp = nums[con+1];
                nums[con + 1] = nums[con];
                nums[con] = temp;
                con++;
            }
            continue;
        }
        i++;
    }
    return nums;
}
