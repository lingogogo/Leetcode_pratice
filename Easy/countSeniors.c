int countSeniors(char ** details, int detailsSize){
    int num = 0;
    int con = 0;
    for(int j = 0; j < detailsSize; j++)
    {
        for(int i = 11; i<13;i++)
        {
            num += details[j][i] - '0';
            if(i==11)
            {
                num*=10;
            }
            
        }
        if(num > 60) con++;
        num = 0;
    }
    return con;
    
}
