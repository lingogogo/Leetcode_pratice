/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int r = 0,c = 0;
    int* return_arr = (int*)malloc(sizeof(int)*matrixSize*(*matrixColSize));
    *returnSize = matrixSize*(*matrixColSize);
    int r_max = matrixSize - 1, c_max = *matrixColSize - 1;
    int r_min = 1, c_min = 0;
    int con = 0;
    for(int i = 0 ; i < *returnSize;)
    {
        while((r+c) <= (r_max+c_max))
        {
            return_arr[i++] = matrix[r][c];
            if(c < c_max)c++;
            else if(r < r_max)r++;
            else break;
        }
        if(i == *returnSize) break;
        r_max--,c_max--;
        c--;
        while((c+r)>=(r_min+c_min))
        {
            return_arr[i++] = matrix[r][c];
            if (c > c_min) c--;
            else if (r > r_min) r--;
            else break;
        }
        r_min++;
        c_min++;
        c++;


    }
    return return_arr;
}
