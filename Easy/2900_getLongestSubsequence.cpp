// class Solution {
// public:
//     vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
//         priority_queue<pair<int,int>> pq1;
//         priority_queue<pair<int,int>> pq0;

//         int n = groups.size();

//         for(int i = 0 ;i < n; i++)
//         {
//             if(groups[i] == 1){
//                 pq1.push({words[i].size(), i});
//             }else if(groups[i] == 0){
//                 pq0.push({words[i].size(),i});
//             }
//         }
//         vector<string> output;
//         int cur = 1;
//         if(pq1.empty()) cur = 0;

//         // cout << pq1.size() << " " << pq0.size() << endl;

//         while(true){
//             if(cur == 0 && !pq0.empty())
//             {
//                 // cout << "0 group" << endl;
//                 auto temp = pq0.top();
//                 output.push_back(words[temp.second]);
//                 // cout << words[temp.second] << endl;
//                 pq0.pop();
//                 cur = 1;
//             }else if(cur == 1 && !pq1.empty()){
//                 // cout << "1 group" << endl;
//                 auto temp = pq1.top();
//                 output.push_back(words[temp.second]);
//                 // cout << words[temp.second] << endl;
//                 pq1.pop();
//                 cur = 0;
//             }
//             // cout << "in" << endl;
//             // cout << pq0.size() << endl;
//             // cout << "cur: " << cur << endl;
            
//             if(cur == 0 && pq0.empty()) break;
//             else if(cur == 1 && pq1.empty()) break;
//         }

//         return output;
//     }
// };


class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        int cur_val = groups[0];
        vector<string> output;
        for(int i = 0; i < n; i++)
        {
            if(cur_val == groups[i]){
                output.push_back(words[i]);
                if(cur_val == 0) cur_val = 1;
                else cur_val = 0;
            }
        }
        return output;
    }
};
