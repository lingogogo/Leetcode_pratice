// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         return dfs(inorder,postorder);
//     }

//     TreeNode* dfs(vector<int>& inorder, vector<int>& postorder)
//     {
//         if(!inorder.empty())
//         {
//             int temp = postorder.back();
//             postorder.pop_back();
//             // find iterator index
//             auto it = find(inorder.begin(),inorder.end(),temp);
//             int ind = it - inorder.begin();
            
//             TreeNode* node = new TreeNode(temp);
//             vector<int> rightinorder(inorder.begin()+ind+1,inorder.end());
//             vector<int> leftinorder(inorder.begin(),inorder.begin() + ind);
//             // cout << "correc happen" << endl;
           
//             // cout << "end" << endl;
//             node->right = dfs(rightinorder,postorder);
//             node->left = dfs(leftinorder,postorder);
            
//             return node;
//         }
//         return nullptr;
//     }
// };

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return constructTree(inorder, postorder, inorderIndexMap, postIndex, 0, inorder.size() - 1);
    }

    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inorderIndexMap, int& postIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        // cout << "inStart: " << inStart << " inEnd: " << inEnd << endl;
        int rootVal = postorder[postIndex--];
        // cout << rootVal << endl;
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = inorderIndexMap[rootVal];
        // cout << "left" << endl;
        root->right = constructTree(inorder, postorder, inorderIndexMap, postIndex, rootIndex + 1, inEnd);
        root->left = constructTree(inorder, postorder, inorderIndexMap, postIndex, inStart, rootIndex - 1);
        // cout << "right" << endl;

        return root;
    }
};
