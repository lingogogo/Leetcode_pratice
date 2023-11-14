class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,vector<int>> dic;
        for(int i = 0; i < s.size(); i++)
        {
            dic[s[i]].push_back(i);
        }
        int val = 0;
        for(auto it = dic.begin(); it != dic.end(); it++)
        {
            if(it->second.size()>1)
            {
                unordered_set<char> count;
                for(int i = it->second[0] + 1; i < it->second[it->second.size() - 1];i++)
                {
                    count.insert(s[i]);
                }
                val+=count.size();
            }
        }
        return val;
    }
};
