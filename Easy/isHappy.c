
int square_n(int n){
    int sum = 0;
    while(n != 0)
    {
        int c = n % 10;
        sum+=pow(c,2);
        n = n/10;
    }
    return sum;
}

bool isHappy(int n){
    // Set up two variable to catch slow one
    int slow = n;
    int fast = square_n(n);
    while(fast!=slow && fast !=1 )
    {
        slow = square_n(slow);
        fast = square_n(square_n(fast));
    }
    if(fast == 1)
        return true;
    return false;
}
