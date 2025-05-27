class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // all distinct
        // find the possible pair of nums and times 8 get the output;
        int output = 0;
        // pass all the possible value
        int n = nums.size();
        unordered_map<int,int> count_fre;
        for(int i = 0 ;i < n; i++)
        {
            for(int j = i + 1; j< n; j++)
            {
                count_fre[nums[i]*nums[j]]++;
            }
        }

        // check all the fre is larger than 2;
        for(auto it:count_fre)
        {
            if(it.second >= 2)
            {
                // cout << it.first << endl;
                // cout << it.second << endl;
                // output+= it.second/2*8;
                output += (it.second -1 ) *it.second/2 * 8;// C^n_2
            }
        }

        return output;
    }
};
