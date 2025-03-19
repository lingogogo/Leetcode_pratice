class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        //沿著i翻過去
        int operations = 0;
        for(int i = 0; i < n-2; i++)
        {
            if(nums[i]==0)
            {
                for(int k = i; k < i+3; k++)
                {
                    if(nums[k] == 0) nums[k] = 1;
                    else nums[k] = 0;
                }
                operations++;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                return -1;
            }
        }
        return operations;
    }
};
