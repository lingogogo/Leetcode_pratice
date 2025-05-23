class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // check increasing or decreasing

        int n = nums.size();
        if(n == 1) return 1;
        // strictly increasing
        int cur = nums[0];
        int output = 0;
        int num1 = 1;
        for(int i = 1;i < n; i++)
        {
            if(nums[i] > cur)
            {
                cur = nums[i];
                num1++;
                output = max(output,num1);
            }else{
                cur = nums[i];
                output = max(output,num1);
                num1 = 1;
            }
        }
        int num2 = 1;
        cur = nums[0];
        for(int i = 1;i < n; i++)
        {
            if(nums[i] < cur)
            {
                cur = nums[i];
                num2++;
                output = max(output,num2);
            }else{
                cur = nums[i];
                output = max(output,num2);
                num2 = 1;
            }
        }
        
        return output;
    }
};
