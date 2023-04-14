int titleToNumber(char * columnTitle){
    int si = 0;
    long tot = 0;
    
    for(int i = 0; i < 8; i++)
    {
        if(columnTitle[i] == '\0')
        {
            si = i;
            break;
        }
    }

    for(int i = 0; i < si; i++)
    {
        tot += (columnTitle[i] - '@')*pow(26,si-i-1);
    }
    
    /*for(i = 0; i<n; i++){
            result*=26;
            result+=(columnTitle[i]- 'A'+1);
     }
    */
    return tot;
}
