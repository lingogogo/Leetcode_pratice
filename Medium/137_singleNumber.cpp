class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Use unordered_map to memory value times.
        unordered_map<int,int> frequency;
        int singlenum = 0;
        int n = nums.size();
        for(int i = 0;i < n; i++)
        {
            frequency[nums[i]]++;
        }

        for(auto& it:frequency)
        {
            if(it.second == 1) return it.first;
        }

        return -1;

    }
};

// better solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans= 0;
        for(int i =0;i<32;i++){
            int sum = 0;
            for(const int num : nums){
                sum += num >> i & 1; // The same number will plus three time
            }
            sum %=3; // Use module find out the extra number (only one)
            ans  |= sum << i; // Use or function to store the one times value
        }
        return ans;
    }
};
