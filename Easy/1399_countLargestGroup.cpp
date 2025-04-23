// Use the unordered_map is slow than the prespace for vector<int>.
// Method 1
class Solution {
public:
    int countLargestGroup(int n) {
        if(n < 10) return n;
        unordered_map<int,int> unmap;
        int max_val = 0;
        for(int i= 1; i <= n; i++)
        {
            int temp = 0;
            int start = i;
            while(start != 0)
            {
                temp += start %10;
                start/=10;
            }
            unmap[temp]++;
            if(max_val < unmap[temp])
                max_val = unmap[temp];
        }

        int output =0;
        for(auto it = unmap.begin(); it!= unmap.end(); it++)
        {
            // cout << it->first << " " << it->second << endl;
            if(max_val == it->second) output++;
        }
        return output;
    }
};
// Method 2
class Solution {
public:
    int countLargestGroup(int n) {
        if(n < 10) return n;
        vector<int> count(37,0);
        int max_val = 0;
        for(int i= 1; i <= n; i++)
        {
            int temp = 0;
            int start = i;
            while(start != 0)
            {
                temp += start %10;
                start/=10;
            }
            count[temp]++;
            if(max_val < count[temp])
                max_val = count[temp];
        }

        int output =0;
        for(int i = 0;i < 37; i++)
        {
            // cout << it->first << " " << it->second << endl;
            if(max_val == count[i]) output++;
        }
        return output;
    }
};
