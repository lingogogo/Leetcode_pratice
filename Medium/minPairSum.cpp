class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max = 0;int n = nums.size();
        // O(n)
        for(int i =0 ; i < (n/2);i++)
        {
            int sum = nums[i] + nums[n - i - 1];
            if(sum > max) max = sum;
        }
        return max;
    }
};
