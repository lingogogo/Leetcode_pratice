/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    int start = 0;
    char** arr = (char**)malloc(20*sizeof(char*));
    int con = 0;
    //2147483648 10 - > 10 22

    for(int i = 0; i< numsSize; i++)
    {
        if(i == 0 ||nums[i] - 1 > nums[i - 1])
            start = nums[i];
        if(i == numsSize - 1 || nums[i] + 1 < nums[i+1]){
            if(start < nums[i])
            {
                arr[con] = (char*)malloc(28*sizeof(char));
                snprintf(arr[con],28,"%d->%d",start,nums[i]);
                con++;
            }else{
                arr[con] = (char*)malloc(28*sizeof(char));
                snprintf(arr[con],28,"%d",nums[i]);
                con++;
            }
        }
    }
    *returnSize = con;
    return arr;
    
}
