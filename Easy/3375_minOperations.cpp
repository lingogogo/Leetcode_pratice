class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // check the nums[i]. The value must be larger than k, or return -1;
        int n= nums.size();
        unordered_set<int> unmap;
        // check the minval == k or minval > k;
        bool minval = false;
        for(int i= 0; i < n ;i++)
        {
            if(nums[i] < k) return -1;
            if(nums[i] == k) minval = true;
            unmap.insert(nums[i]);
        }

        if(minval)
            return unmap.size() - 1;
        else
            return unmap.size();


    }
};
