int lengthOfLastWord(char * s){
    int right = strlen(s) - 1;
    int count = 0;
    for(int i = strlen(s) - 1; i > -1; i--)
    {
        if(s[i] == ' ')
        {
            right--;
        }else
        {
            break;
        }
    }
    for(int i = right; i > -1; i--)
    {
        
        if(s[i]==' ')
        {
            break;
        }
        count++;
    }
    return count;
}
