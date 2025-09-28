// method 1: observe the law (regular pattern) and get the result.
int integerReplacement(int n) {
    int oper = 0;
    // How to judge the operations for the n is odd.
    // if all the operations for the n is n + 1;
    // 11: 11->12->6->3->4->2->1
    // 12: 1100
    // 11: 1011
    // 10: 1010
    // 11: 11->10->5->4->2->1
    long long temp_n = n;
    while(temp_n!=1)
    {
        if(temp_n == 3)
        {
            temp_n-=1;
            oper++;
            continue;
        }
        if(temp_n%2 == 0){
            temp_n/=2;
            oper++;
        }else{
            if(temp_n%4 == 1)
            {
                temp_n -=1;
                oper++;
            }else{
                temp_n+=1;
                oper++;
            }
        }
    }
    return oper;
    
}


// method 2: Using unordered_map to memory the calculated n and decrease the time complexity
// top-bottom dynamic programming

// class Solution {
// private:
//     unordered_map<long long, int> memo;

//     int solve(long long n) {
//         if (n == 1) return 0;
//         if (memo.find(n) != memo.end()) return memo[n];
        
//         int even = INT_MAX;
//         int odd_minus = INT_MAX;
//         int odd_plus = INT_MAX;

//         if (n % 2 == 0) {
//             even = 1 + solve(n / 2);
//         } else {
//             // Handle the case for n-1 and n+1 without overflow issues
//             odd_minus = 1 + solve(n - 1);
//             // Only compute n + 1 if it's within a valid range
//             if (n < LLONG_MAX) {
//                 odd_plus = 1 + solve(n + 1);
//             }
//         }

//         memo[n] = min(even,min(odd_minus, odd_plus));
//         return memo[n];
//     }

// public:
//     int integerReplacement(int n) {
//         return solve(n);
//     }
// };
