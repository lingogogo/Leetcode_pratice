class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> cur_time(n,vector<int>(m,INT_MAX));
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        // BFS + priority queue
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<>> pq;
        // initial cur_time and pq
        pq.push({0,0,0});
        cur_time[0][0] = 0;
        int move_sec = 1;
        while(!pq.empty())
        {
            auto [time,x,y] = pq.top();
            pq.pop();
            if(x == n - 1 && y == m - 1) return time;

            for(auto d:dir)
            {
                int next_x = x + d.first;
                int next_y = y + d.second;
                if((x + y) % 2 == 1)
                    move_sec = 2;
                else{
                    move_sec = 1;
                }
                if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)
                {
                    
                    int time_now = max(moveTime[next_x][next_y],time) + move_sec;
                    
                    if(time_now < cur_time[next_x][next_y]){
                        cur_time[next_x][next_y] = time_now;
                        pq.push({time_now,next_x,next_y});
                    }
                }
            }
            // move_sec++;
            if(move_sec > 2) move_sec = 1;
            // cout << pq.size();
        }
        return -1;

    }
};
