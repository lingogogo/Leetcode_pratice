class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        
        int output = INT_MIN;
        for(int i  = 0; i<n; i++)
        {
            output = max(min(citations[i],n - i),output);
        }
        return output;
    }
};
