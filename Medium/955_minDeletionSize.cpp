class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();

        int ans = 0;

        int m = strs[0].size();
        vector<bool> correct(n,false);
        int uncorrect = n - 1;
        correct[0] = true;
        for(int i = 0;i < m && uncorrect > 0; i++)
        {
            // int old_ans = ans;
            bool pass = true;
            for(int j = 1; j< n; j++)
            {
                if( !correct[j] && strs[j][i] < strs[j - 1][i]){
                    ans++;
                    pass = false;
                    break;
                }// 確保所有的strs都沒有發生違規的情況，如果有，則將pass = false 讓其不進行correct的修改
            }
            if(!pass) continue;
            for(int j = 1; j< n; j++) // 表示所有的strs在同一個position 都是符合條件(後面的strs都大於等於前一個strs) 進行correct的變更
            {
                if(!correct[j] && strs[j][i] > strs[j - 1][i]){
                    correct[j] = true;
                    uncorrect--;
                }
            }
        }

        return ans;
    }
};
