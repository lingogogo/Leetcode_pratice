int maxProduct(int* nums, int n) {
    int target = INT_MIN;
    int premax = 1, premin = 1;
    for(int i = 0;i < n; i++)
    {
        // subarray size is larger than 2.
        int op1 = premax * nums[i];
        // The nums[i] is bigger than befor premax, so start from the nums[i]
        int op2 = nums[i];
        // premin is negative value, and multiply the nums[i](also negative value) to become the largest product.
        int op3 = premin * nums[i];
        // Note: only max_current_product or min_current_product are the important transition value for the max_product_result. The medium value is larger than min_current_product or smaller than max_current_product is invalid for this loop.
        premax = fmax(op1, fmax(op2,op3));
        premin = fmin(op1, fmin(op2,op3));
        target = fmax(target,premax);
    }

    return target;
    
}
