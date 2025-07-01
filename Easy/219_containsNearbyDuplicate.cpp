class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> unmapind;

        int n = nums.size();
        int minlen = INT_MAX;
        for(int i = 0;i < n; i++)
        {
            
            if(unmapind.count(nums[i]))
            {
                if(i - unmapind[nums[i]] <= k) return true;
            }
            unmapind[nums[i]] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> unmapind;

        int n = nums.size();
        int minlen = INT_MAX;
        for(int i = 0;i < n; i++)
        {
            unmapind[nums[i]].push_back(i);
            if(unmapind[nums[i]].size() >= 2)
            {
                minlen = min(minlen,i - *(unmapind[nums[i]].end()-2));
            }
        }
        return (minlen<=k)?true:false;

    }
};
