class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int min_rank = INT_MAX;
        for(int i = 0; i < n;i++)
        {
            min_rank = min(ranks[i],min_rank);
        }

        long long left = 1;
        long long right = long(min_rank)*cars*cars;
        long long middle_time = 0;

        //BS
        while(left <= right)
        {
            middle_time = left + (right - left)/2;
            if(checkfeasible(ranks,cars,n,middle_time)){
                right = middle_time - 1;
            }else{
                left = middle_time + 1;
            }
        }
        return left;
    }

    bool checkfeasible(vector<int>& ranks, int cars, int n, long long middle)
    {
        int repaired_car = 0;
        for(int i = 0; i < n; i++)
        {
            long long temp = middle / ranks[i];
            temp = sqrt(temp);
            repaired_car+=temp;
            if(repaired_car >= cars) return true;
        }
        return false;
    }
};
