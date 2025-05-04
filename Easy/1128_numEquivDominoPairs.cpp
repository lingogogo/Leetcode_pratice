class Solution {
public:
    struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }   
    };
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // unordered_map<pair>
        int n = dominoes.size();
        unordered_map<pair<int,int>,int, pair_hash> unmap;
        int output = 0;
        for(int i = 0; i<n;i++){
            // if(dominoes[i][0] > dominoes[i][1])
            // {
            //     int temp = dominoes[i][0];
            //     dominoes[i][0] = dominoes[i][1];
            //     dominoes[i][1] = temp;
            // }

            // pair<int,int> temp2 = make_pair(dominoes[i][0],dominoes[i][1]);
            if(dominoes[i][0] <= dominoes[i][1]){
                unmap[make_pair(dominoes[i][0],dominoes[i][1])]++;
                output+= unmap[make_pair(dominoes[i][0],dominoes[i][1])] - 1;
            }
            else{
                unmap[make_pair(dominoes[i][1],dominoes[i][0])]++;
                output+= unmap[make_pair(dominoes[i][1],dominoes[i][0])] - 1;
            }              
        }
        
        
        return output;
    }
};
