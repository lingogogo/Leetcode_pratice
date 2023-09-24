class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::string,vector<string>> map_n;
        vector<string> temp = strs;
        vector<string> push;
        /*for(int i = 0; i < strs.size();i++)
        {
            std::sort(temp[i].begin(),temp[i].end());
            map_n.insert(std::pair<std::string,vector<string>>(temp[i],push))
        }*/

        for(int i = 0; i < strs.size();i++)
        {
            std::sort(temp[i].begin(),temp[i].end());
            map_n[temp[i]].push_back(strs[i]);
        }
        vector<vector<string>> output;
        for(auto i = map_n.begin(); i != map_n.end(); i++)
        {
            output.push_back(i->second);
        }
        return output;
    }
};

//link list
