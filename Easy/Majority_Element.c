/*
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int majorityElement(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    return nums[numsSize/2];
}
*/

int majorityElement(int* nums, int numsSize){
    int ma = 0, c = 0;
    for(int i = 0; i< numsSize; i++)
    {
        if(ma == nums[i])
            c++;
        else
            c--;
        
        if(c == -1)
        {
            ma = nums[i];
            c = 0;
        }
           
    }
    return ma;
}
