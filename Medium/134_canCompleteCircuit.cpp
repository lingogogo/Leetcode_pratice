class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // int m = cost.size();
        int total_gas = 0;
        int total_cost = 0;
        vector<int> differ(n,0);
        for(int i = 0;i < n; i++)
        {
            total_gas+=gas[i];
            total_cost+=cost[i];
            differ[i] = gas[i] - cost[i];
        }
        if(total_gas < total_cost) return -1;
        int start_ind = 0;
        for(int i = 0 ;i < n; i++)
        {
            if(differ[i] > 0)
            {
                int sum = differ[i];
                // start_ind = i;
                // int end = i - 1;
                
                int j = i + 1;
                if(j == n) j = 0;
                while(j != i)
                {
                    // cout << j << endl;
                    sum+=differ[j];
                    // cout << "sum: " << sum << endl;
                    j++;
                    if(j == n) j = 0;
                    if(sum < 0)break;
                }
                // cout << "end" << endl;
                if(j == i) start_ind = i;
            }
            
        }
        return start_ind;
    }
};

// better solution
// Just find out the cur_gas is larger than 0 until i == n.
// Don't take the previous cur_gas into consideration, that is because the criterion for suring a solution exist is applied before the for loop.
class Solution {
public:
int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
    const auto total_gas = std::accumulate(gas.begin(), gas.end(), 0);
    const auto total_cost = std::accumulate(cost.begin(), cost.end(), 0);
    if (total_gas < total_cost) return -1;

    // now we know for sure a solution exists.
    int res = 0;
    int curr_gas = 0;
    for (size_t i = 0; i < cost.size(); ++i) {
        curr_gas += gas[i] - cost[i];
        if (curr_gas < 0) {
            // we can skip all prev_res to i since they all will be invalid
            // if starting at prev_res didn't work, prev_res+1 also wont work because to go from prev_res to prev_res+1 there was at least >=0 (excess gas).
            res = i + 1;
            curr_gas = 0;
        }
    }
    return res;
}


};
