class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        //check the non-overlaping
        vector<int> cur = intervals[0];
        int overlap = 0;
        int start = 1;
        while(start < intervals.size())
        {
            //cout << intervals[i][1]<<endl;
            if(intervals[start][0] < cur[1])
            {
                //intervals.erase(intervals.begin()+i);
                if(cur[1] > intervals[start][1])
                {
                    overlap++;
                    cur = intervals[start];
                    start++;
                }else{
                    overlap++;
                    start++;
                }
            }else if(cur[1] <= intervals[start][0])
            {
                cur = intervals[start];
                start++;
            }
        }
        return overlap;
    }
};
