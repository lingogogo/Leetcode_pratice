bool isAnagram(char * s, char * t){
    int maps[26] = {0};
    int i = 0;

    while(s[i] !='\0')
    {
        maps[s[i]-97] +=1;
        i++;
    }
    int j = 0;

    while(t[j] !='\0')
    {
        maps[t[j]-97] -=1;
        if(maps[t[j]-97] < 0)
            return false;
        j++;
    }
    if(i != j)
        return false;
    return true;
}
