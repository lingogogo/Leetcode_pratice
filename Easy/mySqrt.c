int mySqrt(int x){
    // binary tree to search the number
    int start = 0;int last = x; long long mid = (start + last)/2;
    int ans = 0;
    while(last >= start)
    {
        long long pow = mid*mid;
        if(pow == x)
        {
            ans = mid;
            return ans;
        }
        else if(pow > x)
        {
            last = mid - 1;
            mid = (start + last)/2;
        }
        else
        {
            start = mid + 1;
            ans = mid;
            mid = (start + last)/2;
        }
        
    }
    return ans;
}
