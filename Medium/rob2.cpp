class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <=3)
        {
            int max2 = 0;
            for(int i =0 ; i < nums.size();i++)
            {
                if(max2 < nums[i])
                {
                    max2 = nums[i];
                }
            }
            return max2;
        }

        int dp_f[n-1]; dp_f[0] = nums[0]; dp_f[1] = nums[1];
        int dp_b[n-1]; dp_b[0] = nums[1]; dp_b[1] = nums[2];
        //int include_first[n]; include_first[0] = 1; include_first[1] = 0;
        int max_last2 = dp_f[0];
        int max1 = 0;
        for(int i =2 ; i < n - 1; i++)
        {
            if(max_last2 < dp_f[i-2])
            {
                max_last2 = dp_f[i-2];
            }
            dp_f[i] = nums[i] + max_last2;
            cout << dp_f[i] <<endl;
            if(max1 < dp_f[i])
            {
                max1 = dp_f[i];
            }
        }
        max_last2 = dp_b[0];
        for(int i = 2; i < n - 1; i++)
        {
            if(max_last2 < dp_b[i-2])
            {
                max_last2 = dp_b[i-2];
            }
            dp_b[i] = nums[i+1] + max_last2;
            if(max1 < dp_b[i])
            {
                max1 = dp_b[i];
            }
        }
        return max1;
    }
};
