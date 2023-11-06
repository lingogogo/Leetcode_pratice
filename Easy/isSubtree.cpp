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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(recursive(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    /*bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(root == nullptr && subRoot == nullptr) return true;
        else if(root!=nullptr && subRoot == nullptr) return false;
        else if(root==nullptr && subRoot != nullptr) return false;

        if(root->val !=subRoot->val) return false;
        bool a = check(root->left,subRoot->left);
        bool b = check(root->right,subRoot->right);
        return (a==b) ? a:false;

    }*/
    bool recursive(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr) return true;
        else if(root!=nullptr && subRoot == nullptr) return false;
        else if(root==nullptr && subRoot != nullptr) return false;

        bool a = false; bool b = false;
        if(root->val == subRoot->val )
        {
            a = recursive(root->left,subRoot->left);
            b = recursive(root->right,subRoot->right);
            return a&&b;
        }else{
            return false;
        }
    }


    
};
