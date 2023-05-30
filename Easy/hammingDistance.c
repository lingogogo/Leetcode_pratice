int hammingDistance(int x, int y){
    //32 bits
    int ans = x^y;
    int con = 0;
    for(int i = 0; i < 32; i++)
    {
        
        if(ans & 1 == 1) con++;
        ans>>=1;
    }
    return con;
}
