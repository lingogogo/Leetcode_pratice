/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int* array = (int*)malloc(sizeof(int)*n);
    if(n%2 != 0)
    {
        for(int i = 0; i < n; i++)
        {
            array[i] = -n/2 + i;
        }       
    }else
    {
        for(int i = 0; i < n; i++)
        {
            if(i < n/2)
                array[i] = -n/2 + i;
            else
                array[i] = -n/2 + i + 1;
        }  
    }
    
    *returnSize = n;
    return array;
}
