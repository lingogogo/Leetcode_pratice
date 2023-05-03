bool isUgly(int n){
    // check the number is prime factor or not.
    if(n == 1)
        return true;
    if(n == 0)
        return false;
    for(int i = 2; i <= floor(sqrt(n)); i++)
    {
        if(i == floor(sqrt(n)) && n%i !=0 && (n == 2 || n==3 || n==5))
        {
            return true;
        }
        if(n%i == 0)
        {
            break;
        }

    }
    //check its factor is 2,3,5 or not.

    while(n != 1)
    {
        if(n%2 ==0)
        {
            n/=2;
        }else if(n%3 == 0)
        {
            n/=3;
        }else if(n%5 ==0)
        {
            n/=5;
        }
        if(n == 1)
        {
            // it is in 2,3,5
            return true;
        }else if(n%2 !=0 && n%3 !=0 && n%5 !=0)
        {
            break;
        }
    }
    return false;
}

/*bool isUgly(int n){
    if(n<=0){
        return false;
    }
    while(n!=1){
        if(n%3==0){
            n/=3;
        }
        else if(n%2==0){
            n/=2;
        }
        else if(n%5==0){
            n/=5;
        }
        else{
            return false;
        }
    }
    return true;
}*/
