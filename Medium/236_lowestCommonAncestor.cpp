// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> unmap_par;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> temp;
        DFS(root,p,q,temp);

        TreeNode *output = nullptr;
        int i2 = 0;
        for(int i = 0; i < unmap_par[p].size(); i++)
        {
            if(unmap_par[p][i]->val == unmap_par[q][i2]->val)
            {
                output = unmap_par[p][i];
            }
            i2++;
            if(i2 == unmap_par[q].size())
            {
                break;
            }
        }
        return output;
    }
    void DFS(TreeNode* r, TreeNode* p, TreeNode* q, vector<TreeNode*>& temp)
    {
        if(!r) return;
        temp.push_back(r);
        if(r == p || r==q)
            unmap_par[r] = temp;
        DFS(r->left,p,q,temp);
        DFS(r->right,p,q,temp);
        temp.pop_back();
        return;
    }
};
// smart solution with dfs directly
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return left != nullptr ? left : right;        
    }
};
