class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> dic;
        vector<int> output;
        for(int i =0 ; i < adjacentPairs.size();i++)
        {
            dic[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            dic[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }

        for(auto it = dic.begin();it != dic.end();it++)
        {
            if(it->second.size() ==1){
                output.push_back(it->first);
                output.push_back(it->second[0]);
                dic.erase(it);
                break;
            }
        }

        unordered_map<int,vector<int>>::iterator it;

        while(true)
        {
            it = dic.find(output.back());
            if(it->second.size() ==1)
            {
                break;
            }

            if(it->second[0] != *(output.rbegin() + 1))
                output.push_back(it->second[0]);
            else
                output.push_back(it->second[1]);
            
            
        }

        return output;
    }
};
