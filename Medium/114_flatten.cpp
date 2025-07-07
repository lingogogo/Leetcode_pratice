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
    void checkfunction(TreeNode* root)
    {
        TreeNode* temp = root;
        while(temp)
        {
            cout << temp->val << endl;
            if(temp->right){
                cout << "error" << endl; 
                break;
            } 
            temp = temp->left;
        }
    }
    void dfs(TreeNode* r, TreeNode*& last_r)
    {
        if(!r) return;
        last_r = r;
        dfs(r->left,last_r);
        last_r->left = r->right;
        r->right = nullptr;
        dfs(last_r->left,last_r);

        return;
    }

    void lefttoright(TreeNode* r)
    {
        if(!r) return;
        r->right = r->left;
        r->left = nullptr;
        lefttoright(r->right);
        return;
    }
    void flatten(TreeNode* root) {
        // TreeNode* pre = nullptr;
        // TreeNode* cur = root;
        TreeNode* last_r = nullptr;
        dfs(root,last_r);
        // check function
        // checkfunction(root);

        lefttoright(root);
        return;
    }

    
};
