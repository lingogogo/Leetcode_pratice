// https://leetcode.com/problems/count-the-number-of-powerful-integers/solutions/6634808/naruto-step-by-step-simple-explanation
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countChakraShinobi(finish, limit, s) - countChakraShinobi(start - 1, limit, s);
    }

private:
    long long countChakraShinobi(long long val, int limit, const string& clanSymbol) {
        string chakraFlow = to_string(val);  // Represent the chakra stream (digits of the number)
        int prefixLength = chakraFlow.length() - clanSymbol.length();  // Space left for chakra prefix

        if (prefixLength < 0) return 0;  // Not enough room for the suffix

        // rasenganScroll[i][tightMode] -> DP table: tightMode = 0 (free), 1 (bound to value)
        vector<vector<long long>> rasenganScroll(prefixLength + 1, vector<long long>(2, 0));

        // Base case: we’ve formed all prefix digits, now check suffix validity
        rasenganScroll[prefixLength][0] = 1;  // Free path
        rasenganScroll[prefixLength][1] = chakraFlow.substr(prefixLength) >= clanSymbol ? 1 : 0;
        // cout <<"prefixlength: " <<prefixLength << endl;
        // cout << chakraFlow.substr(prefixLength) << endl;
        // Moving backward through the chakra path
        for (int i = prefixLength - 1; i >= 0; --i) {
            int currentChakra = chakraFlow[i] - '0';

            // Not tight to upper bound → try all digits from 0 to limit
            rasenganScroll[i][0] = (limit + 1) * rasenganScroll[i + 1][0];

            // Tight case: digits must be ≤ current digit in value
            if (currentChakra <= limit) {
                rasenganScroll[i][1] = (long long) currentChakra * rasenganScroll[i + 1][0] + rasenganScroll[i + 1][1];
                // cout << rasenganScroll[i + 1][1] << endl;
            } else {
                rasenganScroll[i][1] = (long long)(limit + 1) * rasenganScroll[i + 1][0];
                // cout << rasenganScroll[i][1] << endl;
            }
        }

        return rasenganScroll[0][1];  // Final count from top of chakra flow
    }
};
