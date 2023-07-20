int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);

    int** arr = (int **)malloc((len1+1)*sizeof(int*));
    for(int i = 0 ; i <= len1; i++)
    {
        arr[i] = (int*)malloc((len2+1)*sizeof(int));
    }

    for(int i = 0; i <= len1; i++)
    {
        for(int j = 0; j <= len2; j++)
        {
            arr[i][j] = 0;
        }
    }

    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(text1[i - 1] == text2[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                if(arr[i][j] < arr[i - 1][j])
                {
                    arr[i][j] = arr[i - 1][j];
                }
                
            }else{
                if(arr[i][j - 1] > arr[i - 1][j])
                {
                    arr[i][j] = arr[i][j - 1];
                }else
                {
                    arr[i][j] = arr[i - 1][j];
                }
                
            }

        }
    }
    return arr[len1][len2];
}
