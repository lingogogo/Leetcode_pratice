class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // node1 is maximum ditance, node 2 is minimized.

        int n = edges.size();
        vector<int> distance_node2(n,INT_MAX);
        vector<int> distance_node1(n,INT_MAX);
        // find the distance about node2
        queue<int> qu;
        qu.push(node2);
        vector<int> visited(n,0);
        int temp_distance_node2 = -1;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            if(visited[node] == 0)
                visited[node] = 1;
            else
                continue;

            temp_distance_node2++;
            if(edges[node]!= -1)
                qu.push(edges[node]);
            // distance_node2[node] = min(temp_distance_node2, distance_node2[node]);
            distance_node2[node] = temp_distance_node2;
        }
        // find the distance about node1
        qu.push(node1);
        vector<int> visited2(n,0);
        int temp_distance_node1 = -1;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            if(visited2[node] == 0)
                visited2[node] = 1;
            else
                continue;

            temp_distance_node1++;
            if(edges[node]!= -1)
                qu.push(edges[node]);
            // distance_node1[node] = min(temp_distance_node1,distance_node1[node]);
            distance_node1[node] = temp_distance_node1;
        }

        // for(int i = 0; i < n; i++)
        // {
        //     cout << "distance_node1 : " << distance_node1[i] << endl;
        //     cout << "distance_node2 : " << distance_node2[i] << endl;
        // }
        // find out the min(max(d1,d2))
        int output_index = -1;
        int output_val = INT_MAX;
        for(int i = 0;i < n ; i++)
        {
            if(max(distance_node1[i],distance_node2[i]) < output_val){
                output_val = max(distance_node1[i],distance_node2[i]);
                output_index = i;
            } 
            // cout <<"output_index: " << output_index << endl;
        }
        return output_index;
    }
};
