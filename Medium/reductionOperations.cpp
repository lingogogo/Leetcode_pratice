class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        vector<int> record_count;
        sort(nums.begin(),nums.end());
        int output = 0;
        int weight = 0;
        int last_v = nums[0];
        for(int i = 1; i < nums.size();i++)
        {
            if(last_v != nums[i])
            {
                weight++;
                last_v = nums[i];
            }
            output+=weight;
        }
        return output;
    }
};
