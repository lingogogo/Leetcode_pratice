// Method1: DFS(TLE)
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> unmap_edges1;
        unordered_map<int,vector<int>> unmap_edges2;
        int n = edges1.size();
        int m = edges2.size();
        for(int i = 0; i <n ; i++)
        {
            unmap_edges1[edges1[i][0]].push_back(edges1[i][1]);
            unmap_edges1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i = 0; i < m; i++)
        {
            unmap_edges2[edges2[i][0]].push_back(edges2[i][1]);
            unmap_edges2[edges2[i][1]].push_back(edges2[i][0]);
        }
        int tree_n = unmap_edges1.size();
        int tree_m = unmap_edges2.size();
        vector<int> max_target(tree_n,0); // a node is always target to itself
        for(int cur_tree1 = 0; cur_tree1 < tree_n; cur_tree1++){
            max_target[cur_tree1] = DFS(unmap_edges1, 0, -1,cur_tree1);
        }
        int max_dis = 0;
        for(int cur_tree2 = 0; cur_tree2 < tree_m; cur_tree2++){
            int temp = DFS(unmap_edges2, 1, -1,cur_tree2);
            max_dis = max(temp, max_dis);
        }
        for(int i = 0 ;i < tree_n; i++)
        {
            max_target[i]+=max_dis;
        }
        return max_target;
    }

    int DFS(unordered_map<int,vector<int>>& unmap, int level, int par, int cur){
        
        int temp = 1;
        if(level % 2 != 0) temp = 0;

        for(auto it: unmap[cur])
        {
            if(it != par){
                temp+=DFS(unmap, level+1,cur,it);
            }
        }

        return temp;

    }
};
// Method2: BFS(TLE)
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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
                if(level % 2 == 0) max_target[cur_tree1]++;
                
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
                if(level % 2 != 0) temp_dis++;
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

// Method3: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/editorial
class Solution {
public:
    int dfs(int node, int parent, int depth,
            const vector<vector<int>>& children, vector<int>& color) {
        int res = 1 - depth % 2;
        color[node] = depth % 2;
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res += dfs(child, node, depth + 1, children, color);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const auto& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        int res = dfs(0, -1, 0, children, color);
        return {res, n - res};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> color1(n);
        vector<int> color2(m);
        vector<int> count1 = build(edges1, color1); // The count1[0] means that the white part, and count1[1] is the black part.
        vector<int> count2 = build(edges2, color2);
        vector<int> res(edges1.size() + 1);
        for (int i = 0; i < n; i++) {
            // Use the color1 to distinguish the current node is the black part or white part.
            res[i] = count1[color1[i]] + max(count2[0], count2[1]);
        }
        return res;
    }
};
