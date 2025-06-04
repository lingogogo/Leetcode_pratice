class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> validcan;
        int n = candidates.size();
        // sort(candidates.begin(),candidates.end());
        for(int i = 0; i < n;i++)
        {
            if(candidates[i] <= target)
            {
                validcan.push_back(candidates[i]);
            }
        }
        recursion(validcan,0,target,{},output,0);

        return output;
    }

    void recursion(vector<int>& can, int val, int& target, vector<int> cur_vec,vector<vector<int>>& output, int start_ind)
    {
        for(int k = start_ind; k< can.size(); k++)
        {
            vector<int> temp = cur_vec;
            if(val + can[k] == target){
                
                temp.push_back(can[k]);
                output.push_back(temp);
            }else if(val + can[k] < target){
                // vector<int> temp = cur_vec;
                temp.push_back(can[k]);
                recursion(can,val + can[k],target,temp,output,k);
            }
        }

        return;
    }
};
