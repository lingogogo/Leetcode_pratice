/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// class Solution {
// public:
//     unordered_map<Node*,Node*> unmap;
//     Node* cloneGraph(Node* node) {
//         // Node* return_node = new Node();
        
//         // we can get the node value;
        
        
//         if(!node) return node;
//         // BFS
//         queue<Node*> qu;
//         // qu.push(node);
//         vector<bool> visited(100,false);
//         Node* return_node = new Node(node->val);
//         unmap[node] = return_node; 
//         qu.push(node);
//         while(!qu.empty()){
            
//             Node* get = qu.front();
//             qu.pop();
//             for(auto nei : get->neighbors)
//             {
//                 if(unmap.find(nei) == unmap.end())
//                 {
//                     unmap[nei] = new Node(nei->val);
//                     qu.push(nei);
//                 }
//                 unmap[get]->neighbors.push_back(unmap[nei]);
//             }            
//         }

//         return return_node;
//     }
// };

// DFS
class Solution{
    public:
    unordered_map<Node*,Node*> unmap;
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        // Node* new_node = new Node(node->val);
        // unmap[node] = new_node;
        Node* return_node = recursion(node);
        return return_node;
    }
    Node* recursion(Node* node){
        if(unmap.find(node) == unmap.end()){
            unmap[node] = new Node(node->val);
        }
        else{
            return unmap[node];
        }
        for(auto nei: node->neighbors)
        {
            unmap[node]->neighbors.push_back(recursion(nei));
        }
        // return;
        // return unmap[node];
        return unmap[node];
    }

};
