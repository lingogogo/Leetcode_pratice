class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sumval = 0;
        for(int i= 0; i < n ;i++)
        {
            sumval += nums[i];
        }
        if(sumval%2 != 0) return false;

        int target = sumval/2;

        // Just find out the one subset fullfill the target number.
        vector<bool> dp(target + 1, false);
        // int targetval = 0;
        dp[0] = true;
        for (int num : nums) {
            for (int currSum = target; currSum >= num; --currSum) {
                dp[currSum] = dp[currSum] || dp[currSum - num];
                // cout << currSum << " " << dp[currSum] << endl;
                if (dp[target]) return true;
            }
        }
        return dp[target];
    }
};
