class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;
        int one = 1;
        int count = 0;
        output.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < 32; j++)
            {
                one = (i>>j) & one;
                if(one == 1) count++;
                else one = 1;
            }
            output.push_back(count);
            count = 0;
        }
        return output;
    }
};

/*
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};
*/
