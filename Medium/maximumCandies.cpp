class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        // If the each child can get z candies
        // k * z is the total candies I need.
        long long total_candy = 0;
        // int min_pile = 1;
        int max_pile = INT_MIN;
        for(int i = 0 ; i < n; i++)
        {
            total_candy+=candies[i];
            // if(min_pile > candies[i]) min_pile = candies[i];
            if(max_pile < candies[i]) max_pile = candies[i];
        }
        // if total candy is larger than the number of children.
        if(k > total_candy) return 0;
        // binary search
        int left = 1;
        int right = max_pile;
        // int output = 0;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (checkfeasible(candies, n, k,middle)) {
                left = middle + 1;
                // output = middle;
            } else {
                right = middle - 1;
            }
            // cout << "left: " << left << endl;
            // cout << "right: " << right << endl;
            // cout << middle <<endl;
            // cout << checkfeasible(candies, n, k,middle) << endl;
        }
        return right;
    }

    // whether the search value can be divided or not
    bool checkfeasible(vector<int>& candies, int n, long long k, int middle)
    {
        long long k_fea = 0;
        for(int i = 0 ; i< n; i++)
        {
            k_fea+= candies[i]/middle;
        }

        if(k_fea >= k) return true;
        else return false;
    }

    
};

// class Solution {
// public:
//     int maximumCandies(vector<int>& candies, long long k) {
//         int n = candies.size();

//         // 計算總糖果數量，並找到最大堆大小
//         long long total_candy = 0;
//         int max_pile = 0; // 避免 INT_MIN 問題
//         for(int i = 0; i < n; i++) {
//             total_candy += candies[i];
//             max_pile = max(max_pile, candies[i]);
//         }

//         // 如果糖果總數小於小孩數，則無法分配
//         if (total_candy < k) return 0;

//         // 二分搜尋範圍 [1, max_pile]
//         int left = 1, right = max_pile;
//         while (left <= right) {
//             int middle = left + (right - left) / 2;
//             if (checkfeasible(candies, n, k, middle)) {
//                 left = middle + 1;  // 嘗試更大的 candy 數
//             } else {
//                 right = middle - 1; // 嘗試更小的 candy 數
//             }
//         }

//         return right;  // 最後 valid 的 `right` 就是最大可分配糖果數
//     }

// private:
//     bool checkfeasible(vector<int>& candies, int n, long long k, int middle) {
//         long long k_fea = 0; // 避免溢位
//         for(int i = 0; i < n; i++) {
//             k_fea += candies[i] / middle;
//         }
//         return k_fea >= k;
//     }
// };

// class Solution {
// public:
//     int maximumCandies(vector<int>& candies, long long k) {
//         int n = candies.size();
//         // If the each child can get z candies
//         // k * z is the total candies I need.
//         long long total_candy = 0;
//         // int min_pile = 1;
//         int max_pile = 0;
//         for(int i = 0 ; i < n; i++)
//         {
//             total_candy+=candies[i];
//             // if(min_pile > candies[i]) min_pile = candies[i];
//             max_pile = max(max_pile, candies[i]);
//         }
//         // if total candy is larger than the number of children.
//         if(k > total_candy) return 0;
//         // binary search
//         int left = 1;
//         int right = max_pile;
//         while (left <= right) {
//             int middle = left + (right - left) / 2;
//             if (checkfeasible(candies, n, k,middle)) {
//                 left = middle + 1;
//             } else {
//                 right = middle - 1;
//             }
//         }
//         return right;
//     }

//     // whether the search value can be divided or not
//     bool checkfeasible(vector<int>& candies, int n, long long k, int middle)
//     {
//         long long k_fea = 0;
//         for(int i = 0 ; i< n; i++)
//         {
//             k_fea+= candies[i]/middle;
//         }

//         if(k_fea >= k) return true;
//         else return false;
//     }

    
// };
