
/*
double findMaxAverage(int* nums, int numsSize, int k){
    
    int number = 0;
    if(numsSize == k)
    {
        for(int j = 0; j < numsSize;j++)
        {
            number+=nums[j];
        }
        
        return (double)number/k;
    }

    int max = -2147483648;
    int i = 0;
    
    
    while(i <= (numsSize - k))
    {
        for(int j = i;j < k + i; j++)
        {
            number+=nums[j];
        }
        if(max < number)
        {
            max = number;
        } 
        number = 0;
        i++;
    }
    
    return (double)max/k; 
}*/

// dynamic programming
double findMaxAverage(int* nums, int numsSize, int k){
    int n = numsSize;
    int* dp = malloc(n * sizeof(int));
    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1] + nums[i];
    }

    int max = dp[k-1];   
    for(int i = k; i < n; i++){
        max = fmax(max, dp[i] - dp[i-k] );
    }   
    return (double)max/k;
}
