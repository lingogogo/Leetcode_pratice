int largestAltitude(int* gain, int gainSize){
    int* altitude = (int*)malloc(sizeof(int)*(gainSize+1));
    altitude[0] = 0; // initial altitude is horizontal line
    int max = 0;
    for(int i = 1; i <= gainSize; i++)
    {
        altitude[i] = altitude[i-1] + gain[i-1];
        
    }

    for(int i = 0; i <= gainSize;i++)
    {
        if(max < altitude[i]) max = altitude[i];
    }
    return max;
}

// The upper code is faster than the lower code.
// Why?
/*
int largestAltitude(int* gain, int gainSize){
    int* altitude = (int*)malloc(sizeof(int)*(gainSize+1));
    altitude[0] = 0; // initial altitude is horizontal line
    int max = 0;
    for(int i = 1; i <= gainSize; i++)
    {
        altitude[i] = altitude[i-1] + gain[i-1];
        if(max < altitude[i]) max = altitude[i];
    }

    return max;
    //for loop is faster than everytimes
}
*/
