// class Solution {
// public:
//     int numTrees(int n) {
//         // Check the right and left tree.
//         int output =0;
//         vector<int> dp(2,0);
//         // dp[0] left;
//         // dp[1] right;


        

//         return output;
//     }
// };
// For root node we have total 1 to n choice. For every ith node we have (l to i-1) choice for left root and (i+1 to r) choice for the right root.
// If we have a valid BST for left subtree and b valid BST for right subtree then we will have a*b valid subtree for current node because Every left subtree BST can pair with every right subtree BST.
// https://leetcode.com/problems/unique-binary-search-trees/solutions/6654202/recursion-memorization-c-intuitive-solution
class Solution {
public:
    int numTrees(int n) {
        int l=1;
        int r=n;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int output = totalBST(n,l,r,dp);
        // cout << dp[l][r] << endl;
        // cout << dp[r - 1][r] << endl;
        for(int i = 0; i <= n; i++){
            for(int j = 0;j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return output;
    }

    int totalBST(int n, int l, int r, vector<vector<int>> &dp){
        // cout << l<< " " << r << endl;
        if(l>r || l==r) return 1; // The void tree is also a tree
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        for(int i=l;i<=r;i++){
            int left = totalBST(n,l,i-1,dp);
            int right = totalBST(n,i+1,r,dp);
            ans += left*right;
        }
        return dp[l][r] = ans;
    }
};
