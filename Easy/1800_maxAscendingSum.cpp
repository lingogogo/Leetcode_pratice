class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int max_sum = nums[0];
        vector<int> modified_sum(n,0);
        modified_sum[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[i - 1]){
                modified_sum[i] = modified_sum[i-1] + nums[i];
                max_sum = max(max_sum,modified_sum[i]);
            }else{
                modified_sum[i] = nums[i];
                max_sum = max(max_sum,modified_sum[i]);
            }
        }
        return max_sum;

    }
};
