class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = - 10000;
        int best_sum = -10000;
        for(int i =0; i < nums.size();i++)
        {
            current_sum=max(current_sum+nums[i],nums[i]);
            if(current_sum > best_sum)
                best_sum = current_sum;
            //cout << current_sum <<endl;
        }
        return best_sum;
    }
};
