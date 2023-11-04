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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int A = count_D_recursive(root->left);
        int B = count_D_recursive(root->right);
        return max(A,B)+1;
    }
    int count_D_recursive(TreeNode* child){
        
        if(child==nullptr)
        {
            return 0;
        }
        int A = count_D_recursive(child->left);
        A++;
        int B = count_D_recursive(child->right);
        B++;
        return max(A,B);
    }
};
