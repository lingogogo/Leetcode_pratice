int arrangeCoins(int n){
    // 1 + 2 + 3 + .... + k
    if (n <= 1){
        return n;
    } 
    int row = 0;
    int i = 1;
    while(n > 0)
    {
        n = n - i;
        i = i + 1;
        row = row + 1;
    }
    if(n == 0) return row;
    else return --row;
}
/*
int arrangeCoins(int n){
    if (n <= 1){
        return n;
    } 
    long low = 1, high = n;
    while (low < high) {
        long mid = low + (high - low) / 2;
        if (mid * (mid + 1) / 2 <= n){
            low = mid + 1;
        }else{
            high = mid;
        } 
    }
    return low - 1;
}
*/
