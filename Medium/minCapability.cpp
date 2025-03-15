class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // find max and min capability

        int n = nums.size();
        int max_cap = INT_MIN;
        int min_cap = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            if(max_cap < nums[i]) max_cap = nums[i];
            if(min_cap > nums[i]) min_cap = nums[i];
        }

        // BS
        while(min_cap <= max_cap)
        {
            int middle = min_cap + (max_cap - min_cap)/2;
            if(checkfeasibility(nums,n,k,middle))
            {
                // move to minimum capability
                max_cap = middle - 1;
            }else{
                min_cap = middle + 1;
            }
            // cout << min_cap <<endl;
            // cout << max_cap <<endl;
            // cout << "middle: " << middle << endl;
        }
        return min_cap;

    }

    bool checkfeasibility(vector<int>& nums,int n, int k, int middle)
    {
        // find the max capability in k numbers, equal to middle number
        // if can find out, return true. Instead, return false.
        int count_small_middle = 0;
        int jump_num = -1;
        for(int i= 0 ;i < n;i++)
        {
            if(jump_num != i && nums[i] <= middle){
                count_small_middle++;
                jump_num = i + 1;
            } 

            if(count_small_middle == k) return true;
        }
        return false;
    }
};
