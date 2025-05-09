// class Solution {
// public:
//     int countBalancedPermutations(string num) {
//         int n = num.size();     
//         int arr[10] = {0};
//         // count frequency and total val
//         int totval = 0;
//         for(int i = 0; i < n; i++)
//         {
//             arr[num[i] - '0']++;
//             totval+=num[i] - '0';
//         }

//         if(totval % 2 == 1 ) return 0;

//         // 
//     }
// };

class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        vector<int> psum(11);
        vector<vector<long long>> comb(maxOdd + 1,
                                       vector<long long>(maxOdd + 1));
        long long memo[10][target + 1][maxOdd + 1];
        memset(memo, 0xff, sizeof(memo));
        //使用C數排列，先將其可能的排列組合結果記錄下來
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            // cout << comb[i][i] << " ";
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;//巴斯卡原理
                // cout << comb[i][j];
            }
            // cout << endl;
        }
        //使用倒序，將所有的可能性進行累加，
        for (int i = 9; i >= 0; i--) {
            psum[i] = psum[i + 1] + cnt[i];
            // cout<<psum[i] <<endl;
        }

        function<long long(int, int, int)> dfs = [&](int pos, int curr,
                                                     int oddCnt) -> long long {
            /* If the remaining positions cannot be legally filled, or if the
             * sum of the elements at the current odd positions is greater than
             * the target value */
            // if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
            //     return 0;
            // }
            if (psum[pos] < oddCnt || curr > target) {
                return 0;
            }
            //檢查其是否符合條件，符合則 return 1;
            if (pos > 9) {
                return curr == target && oddCnt == 0;
            }
            //紀錄已經計算的位置 其pos,現在總和值和剩多少個oddCnt，memory
            if (memo[pos][curr][oddCnt] != -1) {
                return memo[pos][curr][oddCnt];
            }
            /* Even-numbered positions remaining to be filled */
            int evenCnt = psum[pos] - oddCnt;
            long long res = 0;
            for (int i = max(0, cnt[pos] - evenCnt); i <= min(cnt[pos], oddCnt);
                 i++) {
                /* The current digit is filled with i positions at odd
                 * positions, and cnt[pos] - i positions at even positions */
                long long ways =
                    comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i] % MOD;
                res = (res +
                       ways * dfs(pos + 1, curr + i * pos, oddCnt - i) % MOD) %
                      MOD;
            }
            memo[pos][curr][oddCnt] = res;
            return res;
        };

        return dfs(0, 0, maxOdd);
    }
};
