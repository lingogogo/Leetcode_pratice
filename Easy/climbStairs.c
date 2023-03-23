int climbStairs(int n){
    // now, we know this problem is Fibonacci sequence.
    if(n == 1)
    {return n;}
    
    int first = 1;
    int second = 2;
    
    for(int i = 2; i < n;i ++)
    {
        int temp = second;
        second = first + second;
        first = temp;
    }
    return second;
}
