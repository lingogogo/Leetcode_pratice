class Solution {
public:
    string pushDominoes(string dominoes) {
        // two direction

        int n = dominoes.size();
        string output = dominoes; 
        // int fall = 0;
        vector<int> memory_num(n,0);
        int num =0;


        for(int i = 0;i < n; i++)
        {
            // find R

            if(dominoes[i] == 'R')
            {
                num = 100000;
            }else if(dominoes[i] =='L')
            {
                num = 0;
            }
            num = max(--num,0);
            memory_num[i] += num;
            // cout << num << endl;
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(dominoes[i] == 'L')
            {
                num = 100000;
            }else if(dominoes[i] == 'R') num = 0;
            num = max(--num,0);
            memory_num[i] -= num;
        }


        for(int i = 0; i < n; i++)
        {
            if(memory_num[i] > 0) dominoes[i] = 'R';
            else if(memory_num[i] == 0) dominoes[i] = '.';
            else dominoes[i] = 'L';
        }
        return dominoes;
    }
};
