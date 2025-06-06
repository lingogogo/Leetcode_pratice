//https://leetcode.com/problems/decode-ways/solutions/4454037/97-43-easy-solution-with-explanation
//https://leetcode.com/problems/decode-ways/solutions/6744144/video-give-me-10-minutes-how-we-think-about-a-solution
class Solution {
public:
    int numDecodings(string s) {
        int decode_ways = 0;
        if(s[0] == '0') return 0;
        // The zeros position makes the string not decode.

        int n = s.size();
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        dp[1] = 1;// two character have the one possible

        for(int i = 2; i <= n; i++)
        {
            int one = s[i - 1] - '0';
            int two = stoi(s.substr(i - 2,2));

            if(one >= 1 && one <= 9)
            {
                dp[i] += dp[i - 1];
            }

            if(two >= 10 && two <= 26)
            {
                dp[i] += dp[i - 2];
            }
            // if(dp[i - 2] < 3 && dp[i - 1] < 7)
            // {
            //     dp[i] = dp[i - 1] + dp[i - 2];
            // }else if(){

            // }
        }
        return dp[n];
    }
};
