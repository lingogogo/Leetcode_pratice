char * mergeAlternately(char * word1, char * word2){  
    char* array =  (char *)calloc(strlen(word1) + strlen(word2) + 1, sizeof(char));

    int arr_con = 0;
    int w1_con = 0, w2_con = 0;

    while(arr_con <(strlen(word1)+strlen(word2)))
    {
        if(w1_con < strlen(word1))
        {
            array[arr_con] = word1[w1_con];
            w1_con++;
            arr_con++;
        }
        if(w2_con < strlen(word2))
        {
            array[arr_con] = word2[w2_con];
            w2_con++;
            arr_con++;
        }
    } 
       
    return array;
}


//
/*
if(arr_con % 2 ==0 || w2_con == strlen(word2))
{
    array[arr_con] = word1[w1_con];
    w1_con++;
    arr_con++;
}
else if(arr_con % 2 ==0 || w1_con == strlen(word1))
{
    array[arr_con] = word2[w2_con];
    w2_con++;
    arr_con++;
}*/
