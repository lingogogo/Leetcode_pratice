// Runtime error
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int mod = 1000000000 + 7;
        int n = s.size();
        int output = 0;
        vector<int> arr(26,0);

        for(int i = 0; i < n;i++)
        {
            arr[s[i] - 'a']++;
        }
        // int times = t/26;
        // int res = t % 26;
        for(int i = 0; i < t; i++)
        {
            vector<int> move_arr(26,0);
            // move_arr[0] = arr[25];
            // move_arr[1] = (arr[25] + arr[0]) % mod;

            // 遍歷所有的arr
            for(int k = 0; k < 26; k++)
            {
                int upindex = k + nums[k];
                for(int j = k + 1; j <= upindex; j++)
                {
                    if(j < 26)
                        move_arr[j] = (move_arr[j] + arr[k]) % mod;
                    else{
                        move_arr[j%26] = (move_arr[j % 26]+arr[k]) % mod;
                    }
                }
            }
            arr = move_arr;
        }

        for(int i  =0 ;i < 26 ;i++)
        {
            // cout << "final" << endl;
            
            output= (output + arr[i]) % mod;
            // cout << i << " " << arr[i] << endl;
        }

        return output;
    }
};


