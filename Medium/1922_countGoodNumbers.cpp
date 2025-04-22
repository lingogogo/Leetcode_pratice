// class Solution {
// public:
//     int countGoodNumbers(long long n) {
//         // take the digit of n

//         // prime: 2, 3, 5, 7

//         for(int i =1 ;i <= n; i++)
//         {
//             // odd pos: 4 digit
//             // even pos: 0,2,4,6,8;
//             // each pos_1 * each pos_2 *...
//             // 5^((n+1)/2) * 4^(n/2);
//         }
//     }
// };

//https://leetcode.com/problems/count-good-numbers/editorial
class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int countGoodNumbers(long long n) {
        // use fast exponentiation to calculate x^y % mod
        auto quickmul = [](int x, long long y) -> int {
            int ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (long long)ret * mul % mod;
                }
                mul = (long long)mul * mul % mod;
                y /= 2;
            }
            return ret;
        };

        return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
    }
};
