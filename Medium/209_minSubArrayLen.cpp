class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int minlen = INT_MAX;
        int n = nums.size();
        int left = 0;
        int sum = 0;
        for(int right = 0;right < n; right++)
        {
            sum+=nums[right];
            while(sum - nums[left] >= target)
            {
                sum-=nums[left];
                left++;
            }
            if(sum >= target) minlen = min(minlen,right - left + 1);
        }

        return (minlen == INT_MAX)?0:minlen;
    }
};

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int i=0;
//         int j=0;
//         int sum=0;
//         int mn=INT_MAX;
//         while(j<nums.size()){
//             sum+=nums[j];
//             while(sum>=target){
//                 sum-=nums[i];
//                 mn=min(j-i+1,mn);
//                 i++;
//             }
//             j++;
//         }
//         if(mn==INT_MAX){
//             return 0;
//         }
//         return mn;
//     }
// };
