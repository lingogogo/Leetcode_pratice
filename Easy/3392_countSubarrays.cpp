class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int output = 0;
        int n = nums.size();
        
        for(int i = 0; i < n-2; i++)
        {
            int mid = 0;
            int sum = 0;
            for(int j = i; j < i + 3; j++)
            {
                if(j == i + 1)
                {
                    mid = nums[j];
                }else{
                    sum+=nums[j];
                }
            }
            if(mid == sum * 2) output++;
        }

        return output;
    }
};
