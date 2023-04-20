bool isIsomorphic(char * s, char * t){
    // It mean that there are transformation in the two char pointer.
    int maps[256] = {0};
    int mapt[256] = {0};
    int i = 0;
    
    while(s[i]!='\0')
    {
        if(maps[s[i]]==0 && mapt[t[i]]==0)
        {
            maps[s[i]] = i + 1;
            mapt[t[i]] = i + 1;
        }
        else if(maps[s[i]]!=mapt[t[i]])
        {
            return false;
        }
        i++;
    }
    return true;
}
