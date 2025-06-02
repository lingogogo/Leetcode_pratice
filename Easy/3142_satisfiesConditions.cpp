class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        // There are two condition to achieve in this problem.
        int n = grid.size();
        int m = grid[0].size();

        // check the first condition.
        for(int i = 0; i < m; i++)
        {
            for(int j = 1; j < n ; j++)
            {
                if(grid[j][i] != grid[j - 1][i]) return false;
            }
        }
        // This steps just need to check the column number, because the first condition is achieved.
        for(int i = 1; i < m; i++)
        {
            if(grid[0][i] == grid[0][i - 1]) return false;
        }

        return true; // all conditions fullfill.
    }
};
