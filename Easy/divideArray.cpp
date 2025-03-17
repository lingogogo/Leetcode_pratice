class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> unmap;

        for(int i = 0; i < n; i++)
        {
            unmap[nums[i]]++;
        }

        // check the value
        for(auto it = unmap.begin();it!=unmap.end();it++)
        {
            if(it->second%2 != 0) return false;
        }
        return true;
    }
};
