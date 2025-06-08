// class Solution {
// public:
//     vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
//     bool exist(vector<vector<char>>& board, string word) {
        
        
//         //DFS
//         return DFS(board,word,0,0,0,0,0);
//     }

//     bool DFS(vector<vector<char>> &board, string word, int word_ind, int x, int y, int old_x,int old_y)
//     {
//         // if(board[i])
        
        
//         if(board[x][y] == word[word_ind]){
//             // word_ind++;
//             if(word_ind == word.size() - 1) return true;
//             for(int i = 0; i < 4; i++)
//             {
//                 if(x + dir[i][0] < board.size() && y + dir[i][1]<board[0].size() && word_ind < word.size() && x+dir[i][0] != x && y+dir[i][1] !=y){
//                     bool check = DFS(board,word,word_ind+1,x+dir[i][0],y+dir[i][1],x,y);
//                     if(check) return true;
//                 }
//             }
//         }else{
//             for(int i = 0; i < 2; i++)
//             {
//                 if(x + dir[i][0] < board.size() && y + dir[i][1]<board[0].size() && word_ind < word.size()){
//                     bool check = DFS(board,word,word_ind,x+dir[i][0],y+dir[i][1],x,y);
//                     if(check) return true;
//                 }
//             }
//         }
//         return false;
        
        
//     }
// };

class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        unordered_map<char,int> unmap;

        for(int i = 0;i < word.size();i++)
        {
            unmap[word[i]]++;
        }

        if(unmap[word[0]] > unmap[*(word.end() - 1)]){
            reverse(word.begin(),word.end());
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word, int index, int x, int y) {
        int m = board.size();
        int n = board[0].size();

        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        if (board[x][y] != word[index]) return false;

        if (index == word.size() - 1) return true;

        char temp = board[x][y];
        board[x][y] = '#';

        for (auto d : dir) {
            int new_x = x + d[0];
            int new_y = y + d[1];
            if (dfs(board, word, index + 1, new_x, new_y)) {
                board[x][y] = temp;
                return true;
            }
        }

        board[x][y] = temp;

        return false;
    }
};
// https://leetcode.com/problems/word-search/solutions/5767663/video-check-4-directions-with-counting-length-of-a-path
// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int rows = board.size();
//         int cols = board[0].size();
//         unordered_set<string> visited;

//         auto dfs = [&](int r, int c, int k, auto& dfs) -> bool {
//             if (k == word.length()) {
//                 return true;
//             }

//             if (r < 0 || r >= rows || c < 0 || c >= cols || visited.count(to_string(r) + "," + to_string(c)) || board[r][c] != word[k]) {
//                 return false;
//             }

//             visited.insert(to_string(r) + "," + to_string(c));
//             bool res = dfs(r + 1, c, k + 1, dfs) || dfs(r - 1, c, k + 1, dfs) || dfs(r, c + 1, k + 1, dfs) || dfs(r, c - 1, k + 1, dfs);
//             visited.erase(to_string(r) + "," + to_string(c));
//             return res;
//         };

//         unordered_map<char, int> count;
//         for (char c : word) {
//             count[c]++;
//         }

//         if (count[word[0]] > count[word.back()]) {
//             reverse(word.begin(), word.end());
//         }

//         for (int r = 0; r < rows; r++) {
//             for (int c = 0; c < cols; c++) {
//                 if (dfs(r, c, 0, dfs)) {
//                     return true;
//                 }
//             }
//         }

//         return false;        
//     }
// };
