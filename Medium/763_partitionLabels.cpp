class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> last_pos; // 記錄每個字母最後出現的位置
        
        // Step 1: 記錄每個字母最後出現的位置
        for (int i = 0; i < n; i++) {
            last_pos[s[i]] = i;
        }

        vector<int> outputsize;
        int start = 0, end = 0;

        // Step 2: 根據字母最遠出現位置來分割字串
        for (int i = 0; i < n; i++) {
            end = max(end, last_pos[s[i]]); // 更新區段的終點
            if (i == end) { // 當當前索引等於區段終點時，確定一個完整區段
                outputsize.push_back(end - start + 1);
                start = i + 1; // 更新下一個區段的開始位置
            }
        }
        
        return outputsize;
    }
};
