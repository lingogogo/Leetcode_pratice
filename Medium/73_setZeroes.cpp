class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> zerocheck(m,vector<int>(n,1));

        for(int i = 0; i < m ;i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    zerocheck[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < m ;i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(zerocheck[i][j] == 0)
                {
                    zerosoper(matrix,i,j,m,n);
                }
            }
        }
        return;
    }

    void zerosoper(vector<vector<int>>& matrix,int& i,int& j, int& m, int& n)
    {
        // entire row
        for(int jj = 0; jj < n; jj++)
        {
            matrix[i][jj] = 0;
        }
        // entire column
        for(int ii = 0; ii < m; ii++)
        {
            matrix[ii][j] = 0;
        }
        return;
    }
};
