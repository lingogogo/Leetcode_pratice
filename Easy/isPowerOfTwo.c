bool isPowerOfTwo(int n){
    int percet = 0;
    if(n == 0)
        return false;
    else if( n == 1)
        return true;
        
    while(n%2==0)
    {
        n/=2;
        if(n==1)
        {
            return true;
        }
    }
    return false;
}
