int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
bool uniqueOccurrences(int* arr, int arrSize){
    qsort(arr,arrSize,sizeof(int),cmpfunc);

    int map[2001] = {0};
    int temp = arr[0];
    int cou_map = 0;
    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] != temp)
        {
            cou_map++;
            temp = arr[i];
        }
        map[cou_map] += 1;
    }
    qsort(map,cou_map+1,sizeof(int),cmpfunc);
    temp = map[0];
    for(int i =1; i <= cou_map; i++)
    {
        if(temp==map[i]) return false;
        temp = map[i];
    }
    return true;


}
