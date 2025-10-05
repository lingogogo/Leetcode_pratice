class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<pair<bool,bool>>> memo(m,vector<pair<bool,bool>>(n,{false,false}));
        vector<vector<int>> output;
        vector<vector<bool>> wholevisited(m,vector<bool>(n,false));
        for(int i = 0 ;i < m; i++)
        {
            for(int j = 0;j < n; j++)
            {
                // if(i == 1 && j == 3){
                    // if(memo[i][j].first && memo[i][j].second)
                    // {
                    //     output.push_back({i,j});
                    //     continue;
                    // }
                    // if(wholevisited[i][j])
                    // {
                    //     if(memo[i][j].first && memo[i][j].second)
                    //     {
                    //         output.push_back({i,j});     
                    //     }
                    //     continue;
                    // }
                    vector<vector<bool>> visited(m,vector<bool>(n,false));
                    cout << "start [" << i << "]" << ",[" << j << "]" << endl;
                    DFS(heights,memo,i,j,m,n,visited,wholevisited);
                    // wholevisited[i][j] = true;
                    // if(i == 1 && j == 4)
                    // {
                    //     cout << "memo[i][j].first: " << memo[i][j].first << " memo[i][j].second: " << memo[i][j].second << endl;
                    // }
                    if(memo[i][j].first && memo[i][j].second)
                    {
                        output.push_back({i,j});
                    }
                    // cout << "result: " << endl;
                    // for(int texti = 0 ;texti < m; texti++){
                    //     for(int textj = 0; textj < n; textj++)
                    //     {
                    //         if(wholevisited[texti][textj]){
                    //             cout << "x: " << texti << " y: " << textj << endl;
                    //             cout << memo[texti][textj].first << " " << memo[texti][textj].second << endl;
                    //         }
                    //     }
                    // }
                // }
            }
        }

        // for(int i = 0;i < m; i++)
        // {
        //     for(int j = 0; j<n; j++){
        //         for(auto d:dir){
        //             int tempx = i + d.first;
        //             int tempy = j + d.second;
        //             if(tempx >= 0 && tempx <m && tempy >=0 && tempy < n&&heights[i][j] == heights[tempx][tempy] && (memo[i][j].first != memo[tempx][tempy].first || memo[i][j].second != memo[tempx][tempy].second)){
        //                 // cout << "tempx: " << tempx << " tempy: " << tempy << endl;
        //                 if(memo[i][j].first && memo[i][j].second) continue;
        //                 memo[i][j].first |= memo[tempx][tempy].first;
        //                 memo[i][j].second |= memo[tempx][tempy].second;
        //                 if(memo[i][j].first && memo[i][j].second)
        //                     output.push_back({i,j});
        //                 // memo[tempx][tempy].first |= memo[i][j].first;
        //                 // memo[tempx][tempy].second |=memo[i][j].second;
        //             }
        //         }
        //         // if(memo[i][j].first && memo[i][j].second )
        //         // {
        //         //     output.push_back({i,j});
        //         // }
        //     }
        // }
        return output;
    }

    void DFS(vector<vector<int>>& heights, vector<vector<pair<bool,bool>>>& memo,int x, int y, int& m, int& n,vector<vector<bool>>& visited, vector<vector<bool>>&wholevisited ){
        // if(x == 1 && y == 4) cout << "[1,4] is visited" << endl;
        if (wholevisited[x][y]){
            cout << "return now" << endl;
            return;
        } 
        // cout << "x: " << x << " y: " << y << endl;
        visited[x][y] = true;
        if(x == 0 || y == 0){
            memo[x][y].first = true;
        }
        if(x == m - 1 || y == n - 1){
            memo[x][y].second = true;
        }
        if(memo[x][y].first && memo[x][y].second)
        {
            wholevisited[x][y] = true;
            // cout << "x: " << x << " y: " << y <<" return" <<endl;
            return;
        }
        // if(wholevisited[x][y]){
        //     return;
        // }
        for(auto d:dir){
            int tempx = x + d.first;
            int tempy = y + d.second;
            if(tempx >= 0 && tempx <m && tempy >=0 && tempy < n && heights[tempx][tempy] <= heights[x][y]){
                if(visited[tempx][tempy] ){
                    continue;
                }
                // cout << "tempx: " << tempx << " tempy: " << tempy << endl;
                DFS(heights,memo,tempx,tempy,m,n,visited,wholevisited);
                if(tempx == 1 && tempy == 3) cout << "visited2" << endl;
                memo[x][y].first |= memo[tempx][tempy].first;
                memo[x][y].second |= memo[tempx][tempy].second;
                if(heights[tempx][tempy] == heights[x][y]){
                    
                    memo[tempx][tempy].first |= memo[x][y].first;
                    memo[tempx][tempy].second |=memo[x][y].second;
                }
                // memo[tempx][tempy].first |= memo[x][y].first;
                // memo[tempx][tempy].second |=memo[x][y].second;
            }
            
        }
        wholevisited[x][y] = true;
        return;
    }
//     void DFS(vector<vector<int>>& heights, vector<vector<pair<bool,bool>>>& memo,
//          int x, int y, int& m, int& n, vector<vector<bool>>& visited,
//          vector<vector<bool>>& wholevisited ) {

//     visited[x][y] = true;

//     if (x == 0 || y == 0)
//         memo[x][y].first = true;
//     if (x == m - 1 || y == n - 1)
//         memo[x][y].second = true;

//     for (auto d : dir) {
//         int tempx = x + d.first;
//         int tempy = y + d.second;

//         if (tempx >= 0 && tempx < m && tempy >= 0 && tempy < n
//             && heights[tempx][tempy] <= heights[x][y]) {
            
//             if (!visited[tempx][tempy])
//                 DFS(heights, memo, tempx, tempy, m, n, visited, wholevisited);
            
//             memo[x][y].first |= memo[tempx][tempy].first;
//             memo[x][y].second |= memo[tempx][tempy].second;
//         }
//     }

//     // ✅ 現在才是正確設置 visited 的時機點
//     wholevisited[x][y] = true;
// }
};

// class Solution {
// private:
// void dfs(int x,int y, vector<vector<int>> &heights ,vector<vector<int>>& vis ){
//     int n=heights.size();
//     int m=heights[0].size();
//     vis[x][y]=1;

//     int delx[]={-1,0,1,0};
//     int dely[]={0,1,0,-1};
//     for(int i=0;i<4;i++){
//         int newx=x+delx[i];
//         int newy=y+dely[i];
// // vis mark is must
//         if(newx>=0 && newx<n && newy>=0 && newy<m &&!vis[newx][newy] && heights[newx][newy]>=heights[x][y]){
//             dfs(newx,newy,heights,vis);
//         }
//     }
// }
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int n=heights.size();
//         int m=heights[0].size();
//         // set<pair<int,int>> Pacific;
//         // set<pair<int,int>> Atlantic;
//         vector<vector<int>> res;
//         vector<vector<int> > visP(n,vector<int> (m,0));
//         vector<vector<int> > visA(n,vector<int> (m,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 // pacific
//                 if(i==0 || j==0){
//                     dfs(i,j,heights , visP);
//                 }
//                 // atlantic
//                 if(i==n-1 || j==m-1){
//                     dfs(i,j,heights , visA );
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(visP[i][j]==1 && visA[i][j]==1){
//                     res.push_back({i,j});
//                 }
//             }
//         }
// return res;
//     }
// };

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int j = 0; j < n; j++) dfs(0, j, heights, pacific);
        for (int i = 0; i < m; i++) dfs(i, 0, heights, pacific);

        for (int j = 0; j < n; j++) dfs(m-1, j, heights, atlantic);
        for (int i = 0; i < m; i++) dfs(i, n-1, heights, atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        
        for (auto& d : directions) {
            int x = i + d[0], y = j + d[1];
            
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (visited[x][y]) continue;
            if (heights[x][y] < heights[i][j]) continue;
            
            dfs(x, y, heights, visited);
        }
    }
};
