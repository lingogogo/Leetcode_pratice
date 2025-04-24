// method1
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> dis_set;
        int n = nums.size();
        for(int i = 0;i < n; i++)
        {
            dis_set.insert(nums[i]);
        }

        int dis_num = dis_set.size();
        int output = 0;
        for(int i =0;i < n; i++)
        {
            unordered_set<int> count_dis;
            for(int j = i; j < n; j++)
            {
                count_dis.insert(nums[j]);

                if(count_dis.size() == dis_num){
                    output+= n - j;
                    break;
                }
            }
        }
        return output;
    }
};
// method2: faster than method1, due to right is move right and without restart right number.
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnt;
        int n = nums.size();
        int right = 0;
        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinct_count = distinct.size();

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                int remove = nums[left - 1];
                cnt[remove]--;
                if (cnt[remove] == 0) {
                    cnt.erase(remove);
                }
            }
            while (right < n && cnt.size() < distinct_count) {
                int add = nums[right];
                cnt[add]++;
                right++;
            }
            if (cnt.size() == distinct_count) {
                res += (n - right + 1);
            }
        }
        return res;
    }
};
