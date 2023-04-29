/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    digits[digitsSize-1]+= 1;
    int con = 0;
    for(int i = digitsSize - 1; i > 0; i--)
    {
        if(digits[i] == 10 && i >0)
        {
            digits[i - 1] +=1;
            digits[i] = 0;
        }
    }
    int* return_num = (int*)malloc(sizeof(int)*(digitsSize+1));
    if(digits[0] == 10)
    {
        return_num[0] = 1;
        for(int i = 1; i < (digitsSize + 1); i++)
        {
            if(digits[i - 1] == 10)
                return_num[i] = 0;
            else
                return_num[i] =  digits[i-1];
        }
        *returnSize = digitsSize+1;
        return return_num;
    }
    *returnSize = digitsSize;
    return_num = digits;
    return return_num;

}
