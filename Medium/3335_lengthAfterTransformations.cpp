class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
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
            move_arr[0] = arr[25];
            move_arr[1] = (arr[25] + arr[0]) % mod;
            for(int j = 2; j < 26; j++)
            {
                move_arr[j] = arr[j - 1];
            }
            arr = move_arr;
        }

        for(int i  =0 ;i < 26 ;i++)
        {
            output= (output + arr[i]) % mod;
            // cout << arr[i] << endl;
        }

        return output;
    }
};
