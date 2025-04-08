class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> unmap;

        int n =nums.size();
        for(int i = 0;i < n; i++)
        {
            unmap[nums[i]]++;
        }
        int oper = 0;
        
        while(checkdistinct(unmap)){
            oper++;
            if(oper*3 <= n){
                
                for(int i = (oper-1)*3 ; i < oper*3; i++)
                {
                    if(unmap.find(nums[i])!= unmap.end())
                        unmap[nums[i]]--;
                    if(unmap[nums[i]] == 0) unmap.erase(nums[i]);
                }
            }else{
                return oper;
            }
        }
        return oper;
        
    }
    // check the unmap;
    bool checkdistinct(unordered_map<int,int>& unmap)
    {
        for(auto it = unmap.begin(); it != unmap.end(); it++)
        {
            if(it->second > 1) return true;
        }
        return false;
    }
};

