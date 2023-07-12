/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* return_array = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    //Next, we have to generate the content in the array.

    int product_all = 1;
    int key = 0;
    int count = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 0)
        {
            //There is zero term in the nums vector.
            key = 1;
            count++;
        }
        if(nums[i]!=0){
            product_all*=nums[i];
  
        } 
        
    }

    if(key == 0)
    {
        for(int i = 0; i < numsSize; i++)
        {
            return_array[i] = product_all/nums[i];
        }
    }else{
        for(int i =0; i < numsSize; i++)
        {
            if(nums[i]!=0)
            {
                return_array[i] = 0;
            }else if(count < 2)
            {
                return_array[i] = product_all;
            }else{
                return_array[i] = 0;
            }
        }
    }
    return return_array;
    
        
    
}
