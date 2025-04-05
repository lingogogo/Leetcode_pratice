class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int xorsum = 0;
        int n = nums.size();
        vector<vector<int>> subsets;
        // Generate all of the subsets
        generateSubsets(nums, 0, {}, subsets);
        for(int i = 0;i < n; i++)
        {
            recursion(nums[i],nums,xorsum,i,n);
        }

        return xorsum;
    }

    void recursion(int cur_val,vector<int>& nums, int& xorsum, int cur_num, int n)
    {
        if(cur_num < n)
            xorsum += cur_val;
        else
            return;
        for(int i = cur_num + 1; i < n; i++)
        {
            // cout<<cur_num+i << endl;
            int output_val = cur_val^nums[i];
            recursion(output_val,nums,xorsum,i,n);
        }
        return;
    }
    
};
