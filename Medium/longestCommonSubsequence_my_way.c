int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    if(len2 > len1) return longestCommonSubsequence(text2, text1);

    int record_count = 0;
    int record_pos[1000] = {-1};


    // find out the integer array
    for(int i = 0; i < len1;i++)
    {
        for(int j = 0; j < len2; j++)
        {
            //== error
            if(text1[i] == text2[j])
            {
                record_pos[record_count] = j;
                record_count++;
                break;
            }
        }
    }
    //return record_count;
    int return_n = 0;
    int record_array_pos = 0;
    while()
    {
        for(int j = 0;j < len2; j++)
        {
            for(int i = record_array_pos; i < record_count; i++)
            {
                if(record_pos[i] == j)
                {
                    return_n++;
                    record_array_pos = i+1;
                }
            }
            if(record_array_pos == record_count)
            {
                break;
            }
        }
    }
       

    return return_n;
}
