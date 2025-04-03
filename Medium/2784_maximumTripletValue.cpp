// prefix ans suffix array
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // leftmax and rightmax
        int n= nums.size();
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);
        for(int i= 1; i < n ;i++)
        {
            leftmax[i] = max(nums[i - 1],leftmax[i - 1]);
            rightmax[n - i - 1] = max(nums[n -i],rightmax[n - i]);
        }
        long long output =0;
        for(int i= 1; i < n; i++)
        {
            output = max((long long)output, (leftmax[i] - (long long)nums[i])* rightmax[i]);
        }
        return output;
    }
};
