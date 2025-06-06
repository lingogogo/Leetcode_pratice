// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         int arr[2000] = {0}; 
//         int n = prerequisites.size();
//         // unordered_map<int,vector<int>> course_pre;
//         // for(int i = 0 ;i < n; i++)
//         // {
//         //     course_pre[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         //     course_pre[prerequisites[i][1]];
//         // }
//         // if there is a cycle in the directed graph, return false;
//         // or the numcourse is small than total course.
//         vector<int> order;
//         queue<int> qu;

//         qu.push(prerequisites[0][1]);
//     }
// };
// https://leetcode.com/problems/course-schedule/solutions/6804592/2-approaches-using-topological-sort-bfs-kahn-s-algo-dfs-tc-o-v-e-sc-o-v-e
class Solution {
public:

    void topoSortBFS(vector<int> &topo, unordered_map<int, list<int>> &adjList, int &numCourses) {
        
        unordered_map<int, int> indegree;

        // preparre indegree
        for (auto unbr : adjList) {
            // int u = unbr.first; // redundant
            for (auto nbr : unbr.second) {
                int v = nbr;
                indegree[v]++;
            }
        }

        // bfs logic
        queue<int> q;
        // init. with indeg 0
        for (int i = 0; i < numCourses; i++) {
            // check if 0 indegree
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            // access front
            int frontNode = q.front();
            q.pop();

            // store ans
            topo.push_back(frontNode);
            // update nbr and 
            for (auto nbr : adjList[frontNode]) {
                // reduce indegree bc we virtually remove the node
                indegree[nbr]--;
                // check if indegree of nbr become 0
                if (indegree[nbr] == 0) {
                    // act like a src ndoe
                    q.push(nbr);
                }
            }
        }
    }

    bool topoSortDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &dfsPath) {
        // mark visitedd
        visited[src] = true;
        dfsPath[src] = true;

        // for each nbr
        for (auto nbr : adjList[src]) {
            // not viisted
            if (!visited[nbr]) {
                bool ans = topoSortDFS(nbr, visited, adjList, dfsPath);
                if (ans) return true;
            }
            // visited and persent in curr path - means cycle present
            else if (visited[nbr] && dfsPath[nbr]) {
                return true;
            }
        }

        // bt
        dfsPath[src] = false;
        // not found
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // make adjList
        unordered_map<int, list<int>> adjList;
        for (auto pre : prerequisites) {
            int u = pre[1];
            int v = pre[0];
            adjList[u].push_back(v);
        }

        // using topo sort cycle detection
        // i will get the order of prereq
        // vector<int> topo;

        // // 01 approach - bfs
        // topoSortBFS(topo, adjList, numCourses);
        // // can be completed
        // return topo.size() == numCourses;

        // 02 approach - dfs
        bool ans = false;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsPath;
        for (int i = 0; i < numCourses; i++) {
            // not visited
            if (!visited[i]) {
                ans = topoSortDFS(i, visited, adjList, dfsPath);
                if (ans) break;
            }
        }
        // cycle found means means cant
        return !ans;
    }
};
