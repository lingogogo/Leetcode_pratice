bool isPowerOfFour(int n){
    
    while(n != 1)
    {
        if(n%4 == 0 && n!=0)n/=4;
        else return false;

    }
    return true;
}
