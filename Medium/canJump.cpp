class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last_index = nums.size() - 1;
        int last = 0;
        if(nums.size() == 1) return 1;
        for(int i =0 ; i < nums.size() - 1; i++)
        {
            
            if(nums[i] + i >= last_index && last >= i)
            {
                return true;
            }else if(nums[i] == 0 && last == i)
            {
                return false;
            }
            last = max(nums[i]+i,last);
            
            //cout << last << endl;
        }
        return false;
    }
};
