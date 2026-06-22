int maxNumberOfBalloons(char* text) {
    int maxballoons = INT_MAX;
    int arr[5] = {0};

    int i = 0;
    while(text[i] != '\0'){
        switch(text[i])
        {
            case 'a':
                arr[0]++;
                break;
            case 'b':
                arr[1]++;
                break;
            case 'n':
                arr[2]++;
                break;
            case 'o':
                arr[3]++;
                break;
            case 'l':
                arr[4]++;
        }
        ++i;
    }

    for(int ii = 0; ii < 5; ii++)
    {
        if(ii < 3) maxballoons = fmin(arr[ii],maxballoons);
        else maxballoons = fmin(arr[ii]/2,maxballoons);
    }

    return maxballoons;
}
