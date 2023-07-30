char * reverseWords(char * s){

    int length = 0;// for ans length
    int count_words = 0;
    int key = 0;// if into a word, turn this to 1;
    
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] !=  ' ' && key == 0)
        {
            length++;
            count_words++;
            key = 1;
        }else if(key == 1 && s[i] != ' ')
        {
            length++;
        }else if(s[i] == ' ' && key == 1)
        {
            key = 0; // encounter a space, and the end of a word;
        }
    }
    
    length = length + count_words - 1;
    char* ans = (char *)calloc(length + 1,sizeof(char));
    
    int length_origin = strlen(s);
    int ans_count = 0;
    int conver_key = 0;
    int left = 0, right = 0;
 
    
    for(int i = length_origin - 1 ;i >= 0; i--)
    {
        if(s[i] != ' ' && conver_key == 0)
        {
            conver_key = 1;
            right = i;
            count_words--;
        }
        
        if(conver_key == 1 && (s[i] == ' ' || i == 0))
        {   
            conver_key = 0;// find another words.
            if(i != 0 || s[i] == ' ')
                left = i+1;
            else 
                left = 0;

            while(left <= right)
            {
                ans[ans_count++] =s[left++]; 
            }

            if(count_words > 0)
            {
                ans[ans_count++] = ' ';
            }
            else ;
            
        }
    }
    return ans;
}
