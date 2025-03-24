class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int freedays = 0;
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());
        int lastendnum = 0;

        for(int i = 0 ;i < n; i++)
        {
            if(meetings[i][0] > lastendnum + 1 )
            {
                freedays+= meetings[i][0] - lastendnum - 1;
            }
            lastendnum = max(lastendnum,meetings[i][1]);
        }

        freedays += days - lastendnum;

        return freedays;

    }
};

// Use difference day
// https://web.ntnu.edu.tw/~algo/Point2.html

// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         map<int, int> dayMap;
//         int prefixSum = 0, freeDays = 0, previousDay = days;
//         bool hasGap = false;

//         for (auto& meeting : meetings) {
//             // Set first day of meetings
//             previousDay = min(previousDay, meeting[0]);

//             // Process start and end of meeting
//             dayMap[meeting[0]]++;
//             dayMap[meeting[1] + 1]--;
//         }

//         // Add all days before the first day of meetings
//         freeDays += (previousDay - 1);

        // difference map
//         for (auto& day : dayMap) {
//             int currentDay = day.first;
//             // Add current range of days without a meeting
//             if (prefixSum == 0) {
//                 freeDays += currentDay - previousDay;
//             }
//             prefixSum += day.second;
//             previousDay = currentDay;
//         }

//         // Add all days after the last day of meetings
//         freeDays += days - previousDay + 1;
//         return freeDays;
//     }
// };
