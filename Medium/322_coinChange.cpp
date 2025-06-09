//
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coinoutput = 0;
        // vector<>
        vector<int> coinvalue(amount + 1, amount + 1);
        int n = coins.size();
        coinvalue[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i - coins[j] >= 0)
                {
                    // cout << "i: " << i << endl;
                    // cout << "coin: " << coins[j] << endl;
                    // cout << coinvalue[i] << endl;
                    // cout << 1 + coinvalue[i - coins[j]] << endl;
                    // cout << endl;
                    coinvalue[i] = min(coinvalue[i],1 + coinvalue[i - coins[j]]);
                }
            }
        }
        if(coinvalue[amount] == amount + 1) return -1;
        else return coinvalue[amount];
        // return 
    }

    // int DFS()
};
