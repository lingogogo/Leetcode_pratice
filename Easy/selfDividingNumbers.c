/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    *returnSize = 0;
    int* array = (int *)malloc(sizeof(int)*(right - left));
    int array_num = 0;
    for(int i = left; i <= right;i++) //1,5 => 1, 2, 3, 4, 5
    {
        int con = i;
        while(true)
        {
            int divider = con%10;
            if(divider == 0) break;
            con/=10;
            if(i%divider != 0) break;
            if(con == 0)
            {
                *returnSize+=1;
                array[array_num++] = i;
            }
        }
    }
    return array;
}
