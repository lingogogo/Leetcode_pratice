class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // try to make the all value to become the same number.
        // may be use binary search
        vector<int> all_val;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                all_val.push_back(grid[i][j]);
            }
        }
        sort(all_val.begin(),all_val.end());
        int n = all_val.size();
        int middian = all_val[n/2];
        int output = 0;
        for(int i = 0; i < n ;i++)
        {
            if(all_val[i] % x != middian % x) return -1;

            output+= abs(middian - all_val[i])/x;
        }

        return output;

    }
};
