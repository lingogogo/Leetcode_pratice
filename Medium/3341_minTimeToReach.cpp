// Not accepted, due to specific update 2-nested loop fix the go through way.
// class Solution {
// public:
//     int minTimeToReach(vector<vector<int>>& moveTime) {
//         int min_time = 0;
//         vector<pair<int,int>> dir = {
//         {1, 0},
//         {-1, 0},
//         {0, 1},
//         {0, -1}};
//         vector<vector<int>> dp(moveTime.size(),vector<int>(moveTime[0].size(), INT_MAX));
//         int n = moveTime.size(), m = moveTime[0].size();
//         for(int i = 0; i < n ;i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 if(i == 0 && j==0)
//                 {
//                     dp[0][0] = 0;
//                     // continue;
//                 }
//                 // cur_pos = [i,j]
//                 for(auto d:dir)
//                 {
//                     int next_x = i + d.first;
//                     int next_y = j + d.second;
//                     if(next_x >= 0 && next_y >=0 && next_x < n && next_y < m)
//                     {
//                         if(dp[i][j] >= moveTime[next_x][next_y])
//                         {
//                             dp[next_x][next_y] = min(dp[i][j] + 1,dp[next_x][next_y]);
//                         }else{
//                             dp[next_x][next_y] = min(moveTime[next_x][next_y]+1,dp[next_x][next_y]);
//                         }
//                         // dp[next_x][next_y] = min(dp[i][j] + moveTime[next_x][next_y] + 1, dp[next_x][next_y]);
//                     }
//                 }
//             }
//         }

        
//         return dp[n - 1][m - 1];
//     }
// };

// Dijkstra algorithms (From chatGPT)
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        time[0][0] = 0;

        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();
            if (x == n-1 && y == m-1) return t;

            for (auto [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int wait = max(t, moveTime[nx][ny]) + 1;
                if (wait < time[nx][ny]) {
                    time[nx][ny] = wait;
                    pq.push({wait, nx, ny});
                }
            }
        }
        // return time[n - 1][m - 1];
        return -1;
    }
};

