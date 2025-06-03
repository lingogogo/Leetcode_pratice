// class Solution {
// public:
//     bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
//         // We need to use the horizontal cut or vertical cut
//         int m = rectangles.size();
//         vector<pair<int,int>> dicx;
//         vector<pair<int,int>> dicy;
//         // The dicx store the position_x in bottom-left corner and top-right corner.
//         for(int i = 0;i  < m ;i++)
//         {
//             dicx.push_back({rectangles[i][0],rectangles[i][2]});
//             dicy.push_back({rectangles[i][1],rectangles[i][3]});
//         }
//         sort(dicy.begin(),dicy.end());
//         // vertical cut; dicy
//         int cur_y = 0;
//         for(int i = 0; i < m; i++)
//         {
//             cur_y = max(cur_y,dicy[i].second);
//         }
//     }
// };
//https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/editorial
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Try both horizontal and vertical cuts
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }

private:
    // Check if valid cuts can be made in a specific dimension
    bool checkCuts(vector<vector<int>>& rectangles, int dim) {
        int gapCount = 0;

        // Sort rectangles by their starting coordinate in the given dimension
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
             });

        // Track the furthest ending coordinate seen so far
        int furthestEnd = rectangles[0][dim + 2];
        // cout <<"dim: " << dim << endl;
        // cout << "Initial furthestEnd: " << furthestEnd << endl;
        for (size_t i = 1; i < rectangles.size(); i++) {
            vector<int>& rect = rectangles[i];
            // cout << rect[dim] << endl;
            // If current rectangle starts after the furthest end we've seen,
            // we found a gap where a cut can be made
            if (furthestEnd <= rect[dim]) {
                // cout << "furthestEnd: " << furthestEnd <<" " << rect[dim] <<endl;
                gapCount++;
            }

            // Update the furthest ending coordinate
            furthestEnd = max(furthestEnd, rect[dim + 2]);
        }

        // We need at least 2 gaps to create 3 sections
        // cout << "Total gapCount: " << gapCount <<endl;
        return gapCount >= 2;
    }
};3
