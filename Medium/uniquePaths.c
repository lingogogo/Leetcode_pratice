int uniquePaths(int m, int n){
    if (m == 1 && n == 1)
    {
        return 1;
    }
    int coun[m][n];
    coun[0][0] = 0;

    for (int i = 1; i < n; ++i)
    {
        coun[0][i] = 1;
    }

    for (int i = 1; i < m; ++i)
    {
        coun[i][0] = 1;
    }
  
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            coun[i][j] = coun[i-1][j] + coun[i][j-1];
        }
    }
    return coun[m - 1][n - 1];

}
