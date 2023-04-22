int cmpfunc (const int * a, const int * b) {
   return ( *a - *b );
}
bool containsDuplicate(int* nums, int numsSize){
    qsort (nums, numsSize, sizeof(int), cmpfunc);
    int con = 0, num = 0;
    for(int i = 0; i<numsSize;i++)
    {
        if(num ==nums[i] && i !=0)
        {
            con++;
        }
        num = nums[i];
        if(con==1)
            return true;
    }
    return false;
}
