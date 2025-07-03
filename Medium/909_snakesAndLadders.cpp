class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int min_roll = 0;
        // int curr_y = n - 1;
        // int curr_x = 0; 
        // unordered_map<int,int> modiboard;
        vector<int> modiboard(n*n,INT_MIN);
        int num = 0;
        int x = 0, key_right = 1;
        int finaln = n*n;
        //build the table for the board
        for(int i = n - 1; i >= 0; i--)
        {
            while(num < finaln)
            {
                if(board[i][x] != -1)
                    modiboard[num] = board[i][x] - 1;
                else
                    modiboard[num] = -1;
                // cout << "num: " << num << " result: " << modiboard[num] << endl;
                if(key_right == 1){
                    x++;
                }else{
                    x--;
                }
                num++;
                if(key_right == 1 && x == n){
                    key_right = 0;
                    x--;
                    break;
                }else if(key_right == 0 && x == -1){
                    key_right = 1;
                    x++;
                    break;
                }
                
            }
        }


        // CHECKFUNCTION
        // for(int i = 0; i < finaln ; i++)
        // {
        //     cout << "i: "<<i << " result: " <<modiboard[i] << endl;
        // }
        // Find out the min_roll, use the greedy move.
        // int cur = -1;
        // while(cur != finaln - 1){ 
        //     // check the move
        //     int finaln_pos = min(cur + 6, finaln - 1);
        //     int max_pos = cur+1;
        //     for(int i = cur + 1; i <= finaln_pos; i++)
        //     {
        //         max_pos = max(max_pos,max(modiboard[i],i));
        //         // cout << "max_pos: " << max_pos << endl;
        //         // cout << "modiboard: "<<modiboard[i] << endl;
        //     }
        //     cur = max_pos;
        //     // cout << "cur: " << cur << endl;
        //     min_roll++;
        //     // cur++;
        // }


        // greedy can not solve the problem.
        // pass all the possible solution, BFS
        queue<int> qu;
        qu.push(0);
        vector<int> visited(finaln,0);

        while(!qu.empty())
        {
            int cur_size = qu.size();
            while(cur_size--){
                int cur = qu.front();
                qu.pop();
                // cout << "cur: " << cur << endl;
                // cout << "min_roll: " << min_roll << endl;
                if(cur == finaln - 1) return min_roll;
                // =====TEST=====
                // if(visited[cur] == 1) continue;
                // visited[cur] = 1;
                // =====TEST=====

                // if(visited[cur] == 1) continue;
                // visited[cur] = 1;
                // cout << "cur: " << cur << endl;
                // insert the next move position.
                
                for(int next_pos = cur + 1; next_pos <= min(cur + 6, finaln - 1); next_pos++)
                {
                    
                    int temp = next_pos;
                    // cout << "next_pos(before): " << temp << endl;
                    if(modiboard[temp] != -1){
                        temp = modiboard[next_pos];
                    }
                    // cout << "next_pos(after): " << temp << endl;
                    // cout << temp << endl;
                    if(visited[temp] == 1) continue;
                    // cout << "next_pos(after): " << temp << endl;
                    qu.push(temp);
                    visited[temp] = 1; // must be the visited here, or it will push too many same index into the queue.
                }
                // cout << endl;
            }
            min_roll++;
        }


        return -1;
    }
};
