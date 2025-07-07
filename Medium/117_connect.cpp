/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // dfstwo(root->left,node->right);
        // BFS
        if(!root) return root;
        queue<Node*> qu;
        qu.push(root);

        while(!qu.empty())
        {
            int size = qu.size();
            Node* pre = NULL;
            Node* temp = NULL;
            while(size--){
                temp = qu.front();
                qu.pop();

                if(!pre){
                    pre = temp;
                }else{
                    pre->next = temp;
                    pre = temp;
                }

                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
            temp->next = NULL;
        }

        return root;
    }

    
};
