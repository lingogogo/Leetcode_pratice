int addDigits(int num){
    int tot = 0;

    while(num != 0)
    {
        tot += num%10;
        num /=10;
        if(num == 0 && tot > 9)
        {
            num = tot;
            tot = 0;
        }
    }
    return tot;
}
