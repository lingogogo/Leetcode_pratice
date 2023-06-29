int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int maxOperations(int* nums, int numsSize, int k){
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    int backward = numsSize - 1;
    int forward = 0;
    int sumup = 0;
    int count_k = 0;
    while(backward > forward)
    {
        sumup = nums[forward] + nums[backward];
        if(sumup > k){
            backward--;
        }else if(sumup < k)
        {
            forward++;
        }

        if(sumup == k)
        {
            count_k++;
            forward++;
            backward--;
        }
        //Reset
        sumup = 0;
    }
    return count_k;
}
