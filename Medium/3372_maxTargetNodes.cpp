class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // record bidirectional path
        unordered_map<int,vector<int>> unmap_edges1;
        unordered_map<int,vector<int>> unmap_edges2;
        int n = edges1.size();
        int m = edges2.size();
        for(int i = 0; i <n ; i++)
        {
            unmap_edges1[edges1[i][0]].push_back(edges1[i][1]);
            unmap_edges1[edges1[i][1]].push_back(edges1[i][0]);
        }
        // cout << unmap_edges1[0].size() << endl;
        for(int i = 0; i < m; i++)
        {
            unmap_edges2[edges2[i][0]].push_back(edges2[i][1]);
            unmap_edges2[edges2[i][1]].push_back(edges2[i][0]);
        }
        int tree_n = unmap_edges1.size();
        int tree_m = unmap_edges2.size();
        vector<int> max_target(tree_n,1); // a node is always target to itself
        // cout <<"tree_n: " <<tree_n << endl;
        for(int cur_tree1 = 0; cur_tree1 < tree_n; cur_tree1++)
        {
            // plus the nodes in tree1, the distance is small than k.
            // BFS
            queue<pair<int,int>> qu;
            vector<int> visited(tree_n,0);
            visited[cur_tree1] = 1;
            for(int i = 0; i < unmap_edges1[cur_tree1].size(); i++)
            {
                qu.push({unmap_edges1[cur_tree1][i],1});
            }
            while(!qu.empty())
            {
                int cur_val = qu.front().first;
                int level = qu.front().second;
                qu.pop();
                if(visited[cur_val] == 1){
                    continue;
                }
                visited[cur_val] = 1;

                if(level > k) break;
                max_target[cur_tree1]++;
                for(int j = 0; j < unmap_edges1[cur_val].size(); j++)
                {
                    qu.push({unmap_edges1[cur_val][j],level+1});
                }
            } 
        }

        // Find out the tree2 maximum node, which the distance is smaller than k;
        int max_dis = 0;
        for(int cur_tree2 = 0; cur_tree2 < tree_m; cur_tree2++)
        {
            // BFS
            queue<pair<int,int>> qu;
            vector<int> visited(tree_m,0);
            int temp_dis = 0;
            qu.push({cur_tree2,1});

            while(!qu.empty())
            {
                int cur_val = qu.front().first;
                int level = qu.front().second;
                qu.pop();
                if(visited[cur_val] == 1){
                    continue;
                }
                visited[cur_val] = 1;
                if(level > k) break;
                temp_dis++;
                for(int j = 0; j < unmap_edges2[cur_val].size(); j++)
                {
                    qu.push({unmap_edges2[cur_val][j],level+1});
                }
            }
            max_dis = max(max_dis,temp_dis);
        }

        for(int i = 0 ;i < tree_n; i++)
        {
            max_target[i]+=max_dis;
        }
        return max_target;
    }

};
