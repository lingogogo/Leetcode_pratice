int fib(int n){
    if(n == 1) return 1;
    else if(n==0) return 0;

    //Now n > 1
    int F[31] = {0};
    F[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        F[i] = F[i - 2] + F[i - 1];
    }
    return F[n];
}
