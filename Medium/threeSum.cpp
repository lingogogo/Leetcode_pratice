class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> output;

        map<vector<int>,int> delete_dup;
        int sum_two = 0;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;


            left = i+1;
            right = nums.size()-1;
            
            while(left < right)
            {
                sum_two = nums[i] + nums[left]+nums[right];
                if(sum_two == 0)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    delete_dup[temp] = 1;
                    temp.clear();
                    left++;right--;
                }else if(sum_two < 0)
                {
                    left++;
                }else{
                    right--;
                }
            }
        }

        for(auto it = delete_dup.begin(); it!=delete_dup.end(); it++)
        {
            output.push_back(it->first);
        }
        return output;
    }
};
