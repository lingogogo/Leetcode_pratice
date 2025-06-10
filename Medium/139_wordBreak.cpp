// class Solution {
// public:
//     static bool func(const pair<size_t,size_t>& a, const pair<size_t,size_t>& b) {
//         return a.first < b.first;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = wordDict.size();
//         vector<pair<size_t,size_t>> position;

//         for(int i = 0 ; i < n ; i++){
//             size_t ind_start = s.find(wordDict[i]);
//             if(ind_start != string::npos)
//             {
//                 position.push_back({ind_start,ind_start + wordDict[i].size() - 1});
//             }
//         }
//         sort(position.begin(),position.end(),func);

//         if(position[0].first != 0)
//         {
//             return false;
//         }
//         bool output = false;
//         for(int i = 0; i < position.size(); i++)
//         {
//             if(position[i].first == 0)
//             {
//                 output = DFS(position,s.size(), position[i].second,i);
//             }
//         }
//         return output;
//     }

//     bool DFS(vector<pair<size_t,size_t>>& position, size_t s_size, int pre_ind_end, int cur_ind)
//     {
//         if(pre_ind_end == s_size - 1)
//             return true;
//         bool check = false;
//         for(int i = cur_ind + 1; i < position.size(); i++)
//         {
//             if(position[i].first == pre_ind_end + 1)
//             {
//                 bool check = DFS(position, s_size, position[i].second, i);
//             }
//             if(check) return true;
//         }

//         return false;
//     }
// };
// https://leetcode.com/problems/word-break/editorial
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> words(wordDict.begin(), wordDict.end());
//         queue<int> queue;
//         vector<bool> seen(s.length(), false);
//         queue.push(0);

//         while (!queue.empty()) {
//             int start = queue.front();
//             queue.pop();

//             if (start == s.length()) {
//                 return true;
//             }

//             for (int end = start + 1; end <= s.length(); end++) {
//                 if (seen[end]) {
//                     continue;
//                 }

//                 if (words.find(s.substr(start, end - start)) != words.end()) {
//                     queue.push(end);
//                     seen[end] = true;
//                 }
//             }
//         }

//         return false;
//     }
// };
// https://leetcode.com/problems/word-break/solutions/6743981/video-using-dynamic-programming
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<bool> dp(s.size() + 1, false);
//         dp[0] = true;
//         // start_with: Check the string w is start in the string s.
//         for (int i = 1; i <= s.size(); i++) {
//             for (const string& w : wordDict) {
//                 int start = i - w.length();
//                 if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[s.size()];        
//     }
// };
//https://leetcode.com/problems/word-break/solutions/4387595/c-dfs-memoization
class Solution {
public:
    unordered_set<string> memo;
    bool dfs(string s, vector<string>& wordDict) {
        if(s.size() == 0) return true;
        if(memo.find(s) != memo.end()) return false;
        for(auto w: wordDict) {
            if(s.starts_with(w) && dfs(s.substr(w.size(), s.size()-w.size()), wordDict)) {
                return true;
            }
        }
        memo.insert(s);
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict);
    }
};
