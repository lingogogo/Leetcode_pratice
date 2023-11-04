class Solution {
public:
    int climbStairs(int n) {
        //dynamic programming
        int dy[n];
        if(n > 2)
        {
            dy[0] = 1;
            dy[1] = 2;
        }else if(n == 1) return 1;
        else if(n==2) return 2;
        for(int i = 2; i < n;i++)
        {
            dy[i] = dy[i-1]+ dy[i-2];
        }
        return dy[n-1];
    }
};
