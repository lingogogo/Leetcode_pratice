/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    bool* array = (bool*)malloc(sizeof(bool)*candiesSize);
    *returnSize = candiesSize;
    int max = 0;
    for(int i = 0; i < candiesSize; i++)
    {
        max = (candies[i]>max)?candies[i]:max;
    }

    for(int i =0; i < candiesSize; i++)
    {
        array[i] = ((candies[i] + extraCandies)>=max)?1:0;
    }
    return array;
}
