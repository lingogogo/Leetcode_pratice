class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;
        // int temp_n = n;
        // the first child have a candy, and the second ones have [limit,n-a] candy
        // we just find out the two children candy, and we can find out the last one.
        // for(int a = 0; a <= min(limit,n); a++)
        // {
        //     int temp_n = n;
        //     temp_n -= a; 
        //     // cout << "a: " << a << endl;
        //     for(int b = 0; b <= min(limit,n - a); b++)
        //     {
        //         // temp_n -= b; // temp_n the third child candy.
        //         // cout << "b: " << b;
        //         // cout << " temp_n: " << temp_n << endl;
        //         if((temp_n - b) > limit) continue;
        //         else ways++;
        //         // cout << "ways++ " << endl;
        //     }
        // }

        for(int a = 0; a <= min(limit,n); a++)
        {
            int temp_n = n;
            temp_n -= a;
            if(temp_n > (limit * 2)) continue; // The two children get the over limit candy.
            // the second child candy decide the how many ways we can use. so Find out the maximum value - minimum value.
            // find out the below limit.
            ways += min(limit, temp_n) - max(0,temp_n - limit) + 1;
        }

        return ways;
    }
};

// method 2: Math
// Cite: https://leetcode.com/problems/distribute-candies-among-children-ii/editorial
// class Solution {
// public:
//     long long cal(int x) {
//         if (x < 0) {
//             return 0;
//         }
//         return (long)x * (x - 1) / 2;
//     }

//     long long distributeCandies(int n, int limit) {
//         return cal(n + 2) - 3 * cal(n - limit + 1) +
//                3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2);
//     }
// };
