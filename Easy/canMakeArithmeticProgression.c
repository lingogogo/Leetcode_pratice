int cmp (const void* a, const void* b)
{
    return ( *(int*) a - *(int*)b );
}

/*int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}*/

bool canMakeArithmeticProgression(int* arr, int arrSize){
    // two type of arithmetic progression
    // sort first
    qsort(arr,arrSize,sizeof(int),cmp);
    int step = arr[1] - arr[0];

    for(int i = 1; i < arrSize; i++)
    {
        if((arr[i] - arr[i-1])!= step)
        {
            return false;
        }
    }
    return true;
}
