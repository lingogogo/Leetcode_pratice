int diagonalSum(int** mat, int matSize, int* matColSize){
    int sum = 0;
    for(int i = 0 ; i < matSize; i++)
    {
        for(int j = 0; j< *matColSize; j++)
        {
            if(i==j)
            {
                sum+=mat[i][j];
            }else if(i+j == matSize - 1)
            {
                sum+=mat[i][j];
            }
        }
    }
    return sum;
}


/*int diagonalSum(int** mat, int matSize, int* matColSize){
    int sum = 0;
    int c = 0, r = 0;
    if(matSize == 1 && *matColSize == 1)
    {
        sum = mat[r][c];
        return sum;
    }
    while(r < matSize)
    {
        sum+=mat[r][c];
        c++;
        r++;
    }
    r = 0,c = *matColSize - 1;
    while(r < matSize && c >=0)
    {

        sum += mat[r][c];
        if(r + 1 == c - 1)
        {
            r+=2;
            c-=2;
        }else{
            r++,c--;
        }
    }
    return sum;  
}*/
