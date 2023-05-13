bool isPerfectSquare(int num){
    int left = 0;
    long long right = num;
    long sum = num/2;
    long long power =0;
    if(num == 1)
    {
        return true;
    }
    while(left <=right)
    {
        power = sum*sum;
        if(power > num)
        {
            right = sum - 1;
        }else if(power<num)
        {
            left = sum + 1;

        }else if(power==num)
        {
            return true;
        }
        sum = (left+right)/2;
    }
    return false;
    

}
