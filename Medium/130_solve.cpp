class Solution {
public:
    int dir[5] = {1,0,-1,0,1};
    void bfs(queue<pair<int,int>>& qu, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        while(!qu.empty())
        {
            auto [x,y] = qu.front();
            qu.pop();

            board[x][y] = 'V';

            for(int d = 0; d < 4; d++)
            {
                int newx = x+dir[d];
                int newy = y+dir[d+1];
                if(newx < 0 || newy <0 || newx >= n || newy >= m)
                {
                    continue;
                }

                if(board[newx][newy] == 'O')
                {
                    qu.push({newx,newy});
                }
            }

        }
    }

    void solve(vector<vector<char>>& board) {
        // Go through the edge of board first
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> edgecircle;
        int col = 0;
        int row = 0;
        while(col < m)
        {
            if(board[0][col] == 'O')
            {
                edgecircle.push({0,col});
            }
            if(board[n - 1][col] == 'O')
            {
                edgecircle.push({n-1,col});
            }
            col++;
        }

        while(row < n)
        {
            if(board[row][0] == 'O')
            {
                edgecircle.push({row,0});
            }
            if(board[row][m-1] == 'O')
            {
                edgecircle.push({row,m-1});
            }
            row++;
        }

        // BFS
        bfs(edgecircle,board);

        // V means that the region is not surrounded.

        for(int i = 0;i < n; i++)
        {
            for(int j = 0;j < m; j++)
            {
                if(board[i][j] == 'V') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return;
    }

    
};
