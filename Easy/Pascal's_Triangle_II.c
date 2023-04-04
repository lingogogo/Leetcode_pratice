int* getRow(int rowIndex, int* returnSize){
    
    *returnSize = rowIndex+1;
    int* ans = (int* )malloc(*returnSize*sizeof(int));
    long temp = 1;
    ans[0] = 1;

    for(int i = 1,k = rowIndex; i<=rowIndex; i++,k--)
    {
        temp = temp*k/i;
        ans[i] = temp;
    }

    return ans;
}
