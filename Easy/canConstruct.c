bool canConstruct(char * ransomNote, char * magazine){
    int num = 0;
    int maps[255] ={0};
    
    for(int i = 0; i < strlen(magazine); i++)
    {
        maps[magazine[i]] +=1;
    }

    while(ransomNote[num] !='\0')
    {
        if(maps[ransomNote[num]] > 0)
        {
            maps[ransomNote[num]]-=1;
        }
        else if(maps[ransomNote[num]] == 0)
        {
            return false;
        }
        num++;
    }
    return true;
}
