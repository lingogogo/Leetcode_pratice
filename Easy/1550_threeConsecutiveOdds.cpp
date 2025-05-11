class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cons_odds = 1;
        int n = arr.size();
        int pre_val = 0;
        if(arr[0] % 2 == 1)
            pre_val = 1;
        for(int i = 1; i < n;i++)
        {
            if(arr[i]%2 == 1 && pre_val == 1)
            {
                cons_odds++;
            }else{
                if(arr[i] % 2 == 1)
                    pre_val = arr[i] % 2;
                else
                    pre_val = 0;
                cons_odds = 1;
            }

            if(cons_odds == 3) return true;
        }
        return false;
    }
};
