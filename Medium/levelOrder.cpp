/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> output;
        
        if(root == nullptr) return output;
        q.push(root);

        while(!q.empty())
        {
            vector<int> temp;
            int n =q.size();
            for(int i =0 ;i < n; i++)
            {
                TreeNode* temp_n = q.front();
                q.pop();

                if(temp_n->left!=nullptr)
                    q.push(temp_n->left);
                if(temp_n->right!=nullptr)
                    q.push(temp_n->right);
                temp.push_back(temp_n->val);
            }
            output.push_back(temp);
        }
        return output;


    }
    
};
