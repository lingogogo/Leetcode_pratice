// Method 1
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // If we want the dominoes are the same in top or bottom
        // Check i value in the tops and bottom value for the same condition

        int n = tops.size();
        unordered_map<int,vector<int>> unmap;
        vector<int> temp_vec;
        int max_val = 0, times =0;
        // find out the repeat value
        for(int i =0; i < n; i++)
        {
            unmap[tops[i]].push_back(i);
            unmap[bottoms[i]].push_back(i);

            if(times < unmap[tops[i]].size())
            {
                max_val = tops[i];
                times = unmap[tops[i]].size();
            }

            if(times < unmap[bottoms[i]].size())
            {
                max_val = bottoms[i];
                times = unmap[bottoms[i]].size();
            }
        }
        // cout << max_val << endl;
        // check each i have the same value
        int rotations = 0, toptimes = 0, bottomtimes = 0;
        for(int i = 0 ;i < n ; i++)
        {

            if(tops[i] == max_val && bottoms[i] == max_val)
            {
                continue;
            }else if(tops[i] != max_val && bottoms[i] !=max_val)
            {
                return -1;
            }

            if(tops[i] == max_val)
            {
                toptimes++;
            }

            if(bottoms[i] == max_val){
                bottomtimes++;
            }
        }

        rotations = min(toptimes,bottomtimes);

        return rotations;
    }
};
// Method 2
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int mswaps=INT_MAX;
        for(int val=1;val<=6;val++){
            int tSwap=0, bSwap=0;

            for(int i=0;i<tops.size();i++){
                if(tops[i]!=val && bottoms[i]!=val){tSwap=INT_MAX; bSwap=INT_MAX; break;}

                if(tops[i]!=val){tSwap++;}
                if(bottoms[i]!=val){bSwap++;}
            }

            mswaps = min(mswaps, min(tSwap,bSwap));
        }

        return mswaps==INT_MAX?-1:mswaps;
    }
};
