// class Solution {
// public:
//     long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
//         long long output = 0;
//         int n = nums.size();
//         vector<bool> check(n,false);

//         for(int i = 0;i < n; i++)
//         {
//             if(nums[i] % modulo == k) check[i] = true;
//         }
//     }
// };

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long res = 0;
        int prefix = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i] % modulo == k;
            res += cnt[(prefix - k + modulo) % modulo];
            // cout << 0 % 2<< endl;
            cnt[prefix % modulo]++;
            // cout << res << endl;
        }
        return res;
    }
};
