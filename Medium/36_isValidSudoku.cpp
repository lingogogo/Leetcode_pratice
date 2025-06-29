class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // unordered_map<int,unordered_set<int>> colunmap;
        // unordered_map<int,unordered_set<int>> rowmap;
        unordered_set<char> colunset[9];
        unordered_set<char> rowunset[9];
        unordered_set<char> boxunset[9];
        // unordered_map<>
        // Check the row and column is valid or not
        
        for(int i = 0;i < 9; i++)
        {
            for(int j = 0;j < 9; j++)
            {
                if(board[i][j] == '.') continue;

                int boxind = (i/3)*3 + (j/3);

                if(colunset[j].count(board[i][j]) || rowunset[i].count(board[i][j]) || boxunset[boxind].count(board[i][j]))
                {
                    return false;
                }

                colunset[j].insert(board[i][j]);
                rowunset[i].insert(board[i][j]);
                boxunset[boxind].insert(board[i][j]);

            }
        }
        return true;

        return true;
    }
};
