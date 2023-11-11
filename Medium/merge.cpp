/*class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        
        sort(intervals.begin(),intervals.end());
        int minv = intervals[0][0]; int maxv = intervals[0][1];
        vector<int> temp;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] > maxv)
            {
                temp.push_back(minv);
                temp.push_back(maxv);
                output.push_back(temp);
                temp.clear();
                minv = intervals[i][0];
                maxv = intervals[i][1];
            }
            minv = min(minv,intervals[i][0]);
            maxv = max(maxv,intervals[i][1]);
        }
        temp.push_back(minv);
        temp.push_back(maxv);
        output.push_back(temp);
        
        
        return output;
    }
};*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        sort(intervals.begin(),intervals.end());
        vector<int> cur = intervals[0];
        // cur.push_back(intervals[0])不予許，因為只能push_back(integer);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] > cur[1])
            {
                output.push_back(cur);
                cur = intervals[i];
            }else
            {
                cur[1] = max(intervals[i][1],cur[1]);
            }

        }
        output.push_back(cur);
        return output;
    }
};
