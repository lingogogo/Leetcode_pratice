// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Codec {
// public:

//     void DFS(TreeNode* r, vector<int>& p,vector<int>& in)
//     {
//         if(!r)return;
//         p.push_back(r->val);
//         DFS(r->left,p,in);
//         in.push_back(r->val);
//         DFS(r->right,p,in);
//         return;
//     }
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         vector<int> preorder;
//         vector<int> inorder;

//         DFS(root,preorder,inorder);

//         string encode = "";

//         for(int i = 0;i < preorder.size(); i++)
//         {
//             encode += to_string(preorder[i]) + '&';
//         }
//         encode += '*';
//         for(int i = 0;i < inorder.size();i++)
//         {
//             encode+=to_string(inorder[i])+'&';
//         }
//         // cout << encode << endl;
//         return encode;
//     }
//     TreeNode* build(deque<int>& preorder, vector<int>& inorder)
//     {
//         if(inorder.size() != 0)
//         {
//             int cur_val = preorder.front();
//             preorder.pop_front();
//             // cout << preorder.size() << endl;
//             TreeNode* r = new TreeNode(cur_val);
//             // auto it = find(inorder.begin(),inorder.end(), cur_val);
//             // int ind_inorder = it - inorder.begin();
//             int ind_inorder = 0;
//             for(int i = 0;i < inorder.size(); i++)
//             {
//                 if(cur_val == inorder[i])
//                 {
//                     ind_inorder = i;
//                 }
//             }

//             vector<int> newleftinorder(inorder.begin(), inorder.begin() + ind_inorder);
//             vector<int> newrightinorder(inorder.begin() + ind_inorder + 1, inorder.end());

//             r->left = build(preorder,newleftinorder);
//             r->right = build(preorder,newrightinorder);
//             return r;
//         }
//         return nullptr;
//     }
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         deque<int> preorder;
//         vector<int> inorder;
//         bool prebool = true;
//         int cur = 0;
//         for(int i = 0;i < data.size(); i++)
//         {
//             // if(data[i] != '&' && !prebool)
//             // {
//             //     preorder.push_back(stoi(string(1,data[i])));
//             // }else 
//             if(data[i] == '&' && prebool){
//                 // prebool = true;
//                 // cout << "dasf" << endl;
//                 // cout << data.substr(cur, i - cur) << endl;
//                 preorder.push_back(stoi(data.substr(cur, i - cur)));
//                 // cout << preorder.back() << endl;
//                 cur = i + 1;
//             }else if(data[i] == '*')
//             {
//                 // cout << "* pos" << endl;
//                 prebool = false;
//                 cur = i + 1;
//             }else if(!prebool && data[i] == '&'){
//                 // cout << data.substr(cur, i - cur) << endl;
//                 inorder.push_back(stoi(data.substr(cur, i - cur)));
//                 // cout << inorder.back() << endl;
//                 cur = i + 1;
//             }
//         }
//         // for(int i = 0;i < data)
//         // we get the postorder and inorder.
//         // cout << "build up binary tree" << endl;
//         TreeNode* output = build(preorder,inorder);
//         return output;
        
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

// 使用preorder and inorder 如果遇到repeated value 會導致其無法建立起binary tree;
// example: [3,3,3,3] inorder [3,3,3,3]
// We can know that the upper example cannot be builded up by the preorder and inorder.
// We can use the easy way to solve the problem.
// Use the preorder and record the nullptr position by the DFS()
// The string can build up the treenode without inorder.
class Codec {
public:
    void traverse(TreeNode* node, string& res) {
        if (!node) {
            res.append("N,");
            return;
        }

        res.append(to_string(node->val) + ",");
        traverse(node->left, res);
        traverse(node->right, res);
    }

    string serialize(TreeNode* root) {
        string res;
        traverse(root, res);
        if (!res.empty()) res.pop_back(); // Remove trailing comma
        return res;
    }

    TreeNode* makeTree(queue<string>& values) {
        string snum = values.front();
        values.pop();
        if (snum == "N") return nullptr;

        TreeNode* root = new TreeNode(stoi(snum));
        root->left = makeTree(values);
        root->right = makeTree(values);
        return root;
    }

    TreeNode* deserialize(string data) {
        queue<string> values;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            values.push(token);
        }

        return makeTree(values);
    }
};
