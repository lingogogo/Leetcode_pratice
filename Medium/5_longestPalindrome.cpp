// class Solution {
// public:
//     unordered_set<string> memo;
//     bool isPalindrome(const string& s, int left, int right) {
//         // string temp = s.substr(left,right - left + 1);
//         // if(memo.find(temp) != )
//         while (left < right) {
//             if (s[left] != s[right]) return false;
//             left++;
//             right--;
//         }
//         // memo.insert(s.substr(left,right - left + 1));
//         return true;
//     }

//     string longestPalindrome(string s) {
//         int n = s.size();
//         int maxLen = 0;
//         string result;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i; j < n; ++j) {
//                 if (isPalindrome(s, i, j) && (j - i + 1 > maxLen)) {
//                     maxLen = j - i + 1;
//                     result = s.substr(i, maxLen);
//                 }
//             }
//         }

//         return result;
//     }
// };
// method2: https://leetcode.com/problems/longest-palindromic-substring/solutions/4212564/beats-96-49-5-different-approaches-brute-force-eac-dp-ma-recursion
// Two dimension dp table.
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int max_len = 1;
        int start = 0;
        int end = 0;
        std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));
        
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i] && (i - j <= 1 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};
