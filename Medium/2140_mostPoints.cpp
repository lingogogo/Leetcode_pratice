class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long maxpoints = 0;
        int n = questions.size();
        vector<long long> dp(n,-1);

        maxpoints = recursive(questions,dp,n,0);
        return maxpoints;
        
    }

    long long recursive(vector<vector<int>>& questions, vector<long long>& dp, int n,int ii)
    {
        if(ii >= n) return 0;
        if(dp[ii] != -1) return dp[ii];
        long long num = questions[ii][0] + recursive(questions,dp,n,ii+questions[ii][1] + 1);
        long long other = recursive(questions,dp,n,ii + 1);
        dp[ii] = max(num,other);
        return dp[ii];
    }
};
