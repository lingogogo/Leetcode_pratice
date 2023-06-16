bool isSubsequence(char * s, char * t){
    
    int t_len = strlen(t);
    int s_len = strlen(s);
    if(s_len>t_len)
    {
        return false;
    }
    int s_c = 0;
    for(int i = 0; i < t_len; i++)
    {
        if(t[i] == s[s_c])
        {
            s_c++;
        }
    }

    if(s_c == s_len) 
    {return true;}
    else 
    {return false;}
}
